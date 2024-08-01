#pragma once

// 该头文件用于管理内存的分配、释放，对象的构造、析构

#include "construct.h"
#include "util.h"

namespace mystl {
// 模版类：allocator
// 模版函数代表数据类型
template <class T>
class allocator {
public:
    typedef T value_type;              // 表示容器中存储的元素类型
    typedef T *pointer;                // 允许创建指向T类型对象的指针
    typedef const T *const_pointer;    // 指向常量类型T的指针类型const_pointer
    typedef T &reference;              // 类型T的引用类型reference
    typedef const T &const_reference;  // 对常量类型T的引用类型
    typedef size_t size_type;          // 用于表示大小和索引，保证在所有平台上都有适当的大小
    typedef ptrdiff_t difference_type; // 用于表示两个指针之间的差异，或者容器中元素的相对位置

public:
    static T *allocate();
    static T *allocate(size_type n);

    static void deallocate(T *ptr);
    static void deallocate(T *ptr, size_type n);

    static void construct(T *ptr);
    static void construct(T *ptr, const T &value);
    static void construct(T *ptr, T &&value);

    template <class... Args>
    static void construct(T *ptr, Args &&...args);

    static void destroy(T *ptr);
    static void destroy(T *first, T *last);
};

// 分配
template <class T>
T *allocator<T>::allocate() {
    // ::operator new 是全局的new操作符，用于分配内存，这里使用::表示使用全局命名空间中的
    // operator new ，以确保不会调用类的重载 new 操作符
    // sizeof(T) 计算类型 T 的大小，以字节为单位
    return static_cast<T *>(::operator new(sizeof(T)));
}

template <class T>
T *allocator<T>::allocate(size_type n) {
    if (n == 0)
        return nullptr;
    return static_cast<T *>(::operator new(n * sizeof(T)));
}

// 释放
template <class T>
void allocator<T>::deallocate(T *ptr) {
    if (ptr == nullptr)
        return;
    ::operator delete(ptr);
}

template <class T>
void allocator<T>::deallocate(T *ptr, size_type /*size*/) {
    if (ptr == nullptr)
        return;
    ::operator delete(ptr);
}

// 构造
template <class T>
void allocator<T>::construct(T *ptr) {
    mystl::construct(ptr);
}

template <class T>
void allocator<T>::construct(T *ptr, const T &value) {
    mystl::construct(ptr, value);
}

template <class T>
void allocator<T>::construct(T *ptr, T &&value) {
    mystl::construct(ptr, mystl::move(value));
}

template <class T>
template <class... Args>
void allocator<T>::construct(T *ptr, Args &&...args) {
    mystl::construct(ptr, mystl::forward<Args>(args)...);
}

// 销毁
template <class T>
void allocator<T>::destroy(T *ptr) {
    mystl::destroy(ptr);
}

template <class T>
void allocator<T>::destroy(T *first, T *last) {
    mystl::destroy(first, last);
}

} // namespace mystl
