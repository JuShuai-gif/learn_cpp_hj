#pragma once

#include <atomic>
#include <utility>
#include <type_traits>

template <class T>
class SharedPtr; // Forward declaration

template <class T>
class WeakPtr; // Forward declaration

template <class T>
struct DefaultDeleter { // 默认使用 delete 释放内存
    void operator()(T *p) const {
        delete p;
    }
};

template <class T>
struct DefaultDeleter<T[]> { // 偏特化
    void operator()(T *p) const {
        delete[] p;
    }
};


template <class T>
class ControlBlock {
public:
    std::atomic<int> shared_count;
    std::atomic<int> weak_count;

    ControlBlock() : shared_count(1), weak_count(1) {}

    virtual ~ControlBlock() {}

    virtual void dispose() = 0;
};

template <class T, class Deleter = DefaultDeleter<T>>
class ControlBlockImpl : public ControlBlock<T> {
public:
    T* ptr;
    Deleter deleter;

    ControlBlockImpl(T* p, Deleter d = Deleter()) : ptr(p), deleter(d) {}

    virtual void dispose() {
        if (ptr) {
            deleter(ptr);
            ptr = nullptr;
        }
    }

    virtual ~ControlBlockImpl() {
        dispose();
    }
};

template <class T>
class SharedPtr {
private:
    T* ptr;
    ControlBlock<T>* ctrl_block;

    void release() {
        if (ctrl_block) {
            if (--ctrl_block->shared_count == 0) {
                ctrl_block->dispose();
                if (--ctrl_block->weak_count == 0) {
                    delete ctrl_block;
                }
            }
        }
    }

    template <class U>
    friend class SharedPtr;

    template <class U>
    friend class WeakPtr;

public:
    SharedPtr() : ptr(nullptr), ctrl_block(nullptr) {}

    explicit SharedPtr(T* p) 
        : ptr(p), ctrl_block(new ControlBlockImpl<T>(p)) {}

    template <class U, class Deleter>
    SharedPtr(U* p, Deleter d) 
        : ptr(p), ctrl_block(new ControlBlockImpl<U, Deleter>(p, d)) {}

    SharedPtr(const SharedPtr& other) 
        : ptr(other.ptr), ctrl_block(other.ctrl_block) {
        if (ctrl_block) {
            ++ctrl_block->shared_count;
        }
    }

    SharedPtr(SharedPtr&& other) noexcept 
        : ptr(other.ptr), ctrl_block(other.ctrl_block) {
        other.ptr = nullptr;
        other.ctrl_block = nullptr;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ctrl_block = other.ctrl_block;
            if (ctrl_block) {
                ++ctrl_block->shared_count;
            }
        }
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ctrl_block = other.ctrl_block;
            other.ptr = nullptr;
            other.ctrl_block = nullptr;
        }
        return *this;
    }

    ~SharedPtr() {
        release();
    }

    T* get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    int use_count() const {
        return ctrl_block ? ctrl_block->shared_count.load() : 0;
    }

    bool unique() const {
        return use_count() == 1;
    }

    void reset(T* p = nullptr) {
        release();
        if (p) {
            ptr = p;
            ctrl_block = new ControlBlockImpl<T>(p);
        } else {
            ptr = nullptr;
            ctrl_block = nullptr;
        }
    }

    void swap(SharedPtr& other) noexcept {
        std::swap(ptr, other.ptr);
        std::swap(ctrl_block, other.ctrl_block);
    }
};

template <class T>
class WeakPtr {
private:
    T* ptr;
    ControlBlock<T>* ctrl_block;

    template <class U>
    friend class SharedPtr;

    void release() {
        if (ctrl_block) {
            if (--ctrl_block->weak_count == 0) {
                if (ctrl_block->shared_count == 0) {
                    delete ctrl_block;
                }
            }
        }
    }

public:
    WeakPtr() : ptr(nullptr), ctrl_block(nullptr) {}

    WeakPtr(const SharedPtr<T>& other) 
        : ptr(other.ptr), ctrl_block(other.ctrl_block) {
        if (ctrl_block) {
            ++ctrl_block->weak_count;
        }
    }

    WeakPtr(const WeakPtr& other) 
        : ptr(other.ptr), ctrl_block(other.ctrl_block) {
        if (ctrl_block) {
            ++ctrl_block->weak_count;
        }
    }

    WeakPtr(WeakPtr&& other) noexcept 
        : ptr(other.ptr), ctrl_block(other.ctrl_block) {
        other.ptr = nullptr;
        other.ctrl_block = nullptr;
    }

    WeakPtr& operator=(const WeakPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ctrl_block = other.ctrl_block;
            if (ctrl_block) {
                ++ctrl_block->weak_count;
            }
        }
        return *this;
    }

    WeakPtr& operator=(WeakPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ctrl_block = other.ctrl_block;
            other.ptr = nullptr;
            other.ctrl_block = nullptr;
        }
        return *this;
    }

    ~WeakPtr() {
        release();
    }

    SharedPtr<T> lock() const {
        if (ctrl_block && ctrl_block->shared_count > 0) {
            return SharedPtr<T>(*this);
        }
        return SharedPtr<T>();
    }

    int use_count() const {
        return ctrl_block ? ctrl_block->shared_count.load() : 0;
    }

    bool expired() const {
        return use_count() == 0;
    }

    void reset() {
        release();
        ptr = nullptr;
        ctrl_block = nullptr;
    }

    void swap(WeakPtr& other) noexcept {
        std::swap(ptr, other.ptr);
        std::swap(ctrl_block, other.ctrl_block);
    }
};

template <class T, class Deleter = DefaultDeleter<T>, class... Args>
SharedPtr<T> make_shared(Args&&... args) {
    T* p = new T(std::forward<Args>(args)...);
    return SharedPtr<T>(p, Deleter());
}
