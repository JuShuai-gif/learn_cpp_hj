
#include <atomic>
#include <iostream>
#include <memory>
#include <type_traits>
namespace smp {

template <typename Ty>
struct shared_ptr;

template <typename Ty>
struct weak_ptr;

template <class Ty>
struct enable_shared_from_this;

template <typename Ty>
constexpr auto can_enable_shared = std::is_base_of<enable_shared_from_this<Ty>, Ty>;

template <typename Ty>
struct RefCount {

    RefCount(Ty *raw_ptr) :
        _ptr(raw_ptr) {
    }
    // 增加强引用
    void add_ref() {
        _uses++;
    }
    // 释放强引用
    void sub_ref() {
        if ((--_uses) == 0) {
            destroy_resource();
            sub_wref();
        }
    }
    // 增加弱引用
    void add_wref() {
        _weaks++;
    }
    // 释放 弱引用
    void sub_wref() {
        if ((--_weaks) == 0) {
            delete_this();
        }
    }

    // 尝试增加 uses
    bool try_add_ref() {
        if (_uses == 0) return false;
        _uses++;
        return true;
    }

    // 释放资源
    void destroy_resource() noexcept {
        delete _ptr;
    }
    // 释放自己
    void delete_this() noexcept {
        delete this;
    }

    // 使用计数
    int32_t use_count() {
        return _uses;
    }

private:
    // 原子计数 在一个线程进行某个原子操作时，其它线程不能看到操作一半的状态
    // 表示当前对象被多少个 shared_ptr 拥有
    std::atomic_int32_t _uses = 1;
    // 表示当前对象被多少个 weak_ptr 引用
    std::atomic_int32_t _weaks = 1;

    Ty *_ptr;
};

template <class Ty>
struct Ptr_base {
    Ptr_base() = default;
    Ptr_base(const Ptr_base &) = delete;
    Ptr_base &operator=(const Ptr_base &) = delete;

    Ty *get() const noexcept {
        return _ptr;
    }

    auto use_count() const noexcept {
        return _ref ? _ref->use_count() : 0;
    }

    template <class _Ty2>
    void swap(Ptr_base<_Ty2> &rhs) {
        std::swap(_ptr, rhs._ptr);
        std::swap(_ref, rhs._ref);
    }

private:
    friend class shared_ptr<Ty>;
    friend class weak_ptr<Ty>;
    Ty *_ptr = nullptr;
    RefCount<Ty> *_ref = nullptr;

    void _init(Ty *raw_ptr) {
        _ptr = raw_ptr;
        _ref = new RefCount(raw_ptr);
    }

    void add_ref() const {
        if (_ref) _ref->add_ref();
    }

    void sub_ref() const {
        if (_ref) _ref->sub_ref();
    }

    void add_wref() const {
        if (_ref) _ref->add_wref();
    }

    void sub_wref() const {
        if (_ref) _ref->sub_wref();
    }

    template <class _Ty2>
    void _copy_ptr_from(const Ptr_base<_Ty2> &rhs) {
        _ptr = rhs._ptr;
        _ref = rhs._ref;
    }
    template <class _Ty2>
    void _move_construct_from(Ptr_base<_Ty2> &&rhs) noexcept {
        _copy_ptr_from(rhs);
        rhs._ptr = nullptr;
        rhs._ref = nullptr;
    }

    template <class _Ty2>
    void _copy_construct_from_shared(const shared_ptr<_Ty2> &rhs) noexcept {
        rhs.add_ref();
        _copy_ptr_from(rhs);
    }

    template <class _Ty2>
    void _weakly_construct_from(const Ptr_base<_Ty2> &rhs) noexcept {
        _copy_ptr_from(rhs);
        add_wref();
    }

    template <class _Ty2>
    bool _construct_from_weak(const weak_ptr<_Ty2> &rhs) noexcept {
        if (rhs._ref && rhs._ref->try_add_ref()) {
            _copy_ptr_from(rhs);
            return true;
        }

        return false;
    }
};

template <typename Ty>
struct shared_ptr : public Ptr_base<Ty> {
public:
    using Base = Ptr_base<Ty>;
    shared_ptr() noexcept = default;
    shared_ptr(std::nullptr_t) noexcept {
    } // construct empty shared_ptr
    explicit shared_ptr(Ty *raw_ptr) {
        Base::_init(raw_ptr);
        if constexpr (can_enable_shared<Ty>) {
            raw_ptr->_weak_this_ = *this;
        }
    }

    shared_ptr(const shared_ptr &rhs) {
        Base::_copy_construct_from_shared(rhs);
    }

    shared_ptr &operator=(const shared_ptr &rhs) {
        shared_ptr(rhs).swap(*this);
        return *this;
    }

    shared_ptr(shared_ptr &&rhs) noexcept {
        Base::_move_construct_from(std::move(rhs));
    }

    shared_ptr &operator=(shared_ptr &&rhs) noexcept {
        shared_ptr(std::move(rhs)).swap(*this);
        return *this;
    }

    template <class _Ty2>
    shared_ptr(const weak_ptr<_Ty2> &rhs) noexcept {
        Base::_construct_from_weak(rhs);
    }
    ~shared_ptr() {
        Base::sub_ref();
    }

    Ty &operator*() noexcept {
        return *Base::_ptr;
    }

    const Ty &operator*() const noexcept {
        return *Base::_ptr;
    }

    Ty *operator->() {
        return &*Base::_ptr;
    }
    const Ty *operator->() const {
        return &*Base::_ptr;
    }

    explicit operator bool() const {
        return (Base::_ptr != nullptr);
    }
};

template <typename Ty>
struct weak_ptr : public Ptr_base<Ty> {
public:
    using Base = Ptr_base<Ty>;
    weak_ptr() noexcept = default;
    constexpr weak_ptr(std::nullptr_t) noexcept {
    }

    weak_ptr(const weak_ptr &rhs) {
        Base::_weakly_construct_from(rhs);
    }

    weak_ptr(const shared_ptr<Ty> &rhs) {
        Base::_weakly_construct_from(rhs);
    }

    weak_ptr &operator=(const weak_ptr &rhs) {
        weak_ptr(rhs).swap(*this);
        return *this;
    }

    weak_ptr(weak_ptr &&rhs) noexcept {
        Base::_move_construct_from(std::move(rhs));
    }

    weak_ptr &operator=(weak_ptr &&rhs) noexcept {
        weak_ptr(std::move(rhs)).swap(*this);
        return *this;
    }

    ~weak_ptr() {
        Base::sub_wref();
    }

    shared_ptr<Ty> lock() const noexcept {
        shared_ptr<Ty> ret;
        ret._construct_from_weak(*this);
        return ret;
    }

    bool expired() const {
        return Base::_ref->use_count() == 0;
    }
};

template <typename T, typename... Ts>
shared_ptr<T> make_shared(Ts &&...args) {
    return shared_ptr<T>{new T(std::forward<Ts>(args)...)};
}

template <class Ty>
struct enable_shared_from_this {
    mutable weak_ptr<Ty> _weak_this_;

protected:
    constexpr enable_shared_from_this() noexcept :
        _weak_this_() {
    }
    enable_shared_from_this(const enable_shared_from_this &) noexcept {
    }
    enable_shared_from_this &operator=(const enable_shared_from_this &) noexcept {
        return *this;
    }
    ~enable_shared_from_this() = default;
public:
    shared_ptr<Ty> shared_from_this() {
        return shared_ptr<Ty>(_weak_this_);
    }
    shared_ptr<Ty const> shared_from_this() const {
        return shared_ptr<const Ty>(_weak_this_);
    }
    friend class shared_ptr<Ty>;
};

} // namespace smp

void test_shared() {
    using namespace smp;
    struct A {
        A(int id) :
            _id(id) {
        }
        ~A() {
            std::cout << "id : " << std::to_string(_id) << "  ~A()\n";
        }
        int _id;
    };

    auto s1 = make_shared<A>(1);

    auto s2 = make_shared<A>(2);

    shared_ptr<A> s;
    s1 = std::move(s2);

    s = s1;

    std::cout << s1.use_count() << "\n";

    s1 = make_shared<A>(3);
}

void test_weak() {
    using namespace smp;
    struct A;
    struct B;
    struct A {
        A(int id) :
            _id(id) {
        }
        ~A() {
            std::cout << "id : " << std::to_string(_id) << "  ~A()\n";
        }
        int _id;
        weak_ptr<B> p;
    };
    struct B {
        weak_ptr<A> p;
        B(int id) :
            _id(id) {
        }
        ~B() {
            std::cout << "id : " << std::to_string(_id) << "  ~B()\n";
        }
        int _id;
    };
    {
        auto sa = make_shared<A>(1);
        auto sb = make_shared<B>(2);
        sa->p = sb;
        sb->p = sa;
        auto ss = sa->p.lock();
        std::cout << ss.use_count() << "\n";
    }
    weak_ptr<A> weak_a;
    {
        auto sa = make_shared<A>(1);
        weak_a = sa;
    }
    std::cout << weak_a.expired() << "\n";
}

void test_enable_from() {
    using namespace smp;

    struct A;
    struct B;
    struct A : enable_shared_from_this<A> {
        A(int id) :
            _id(id) {
        }
        ~A() {
            std::cout << "id : " << std::to_string(_id) << "  ~A()\n";
        }
        int _id;
        weak_ptr<B> p;
    };
    struct B : enable_shared_from_this<B> {
        weak_ptr<A> p;
        B(int id) :
            _id(id) {
        }
        ~B() {
            std::cout << "id : " << std::to_string(_id) << "  ~B()\n";
        }
        int _id;
    };
    auto sa = make_shared<A>(1);
    auto sb = make_shared<B>(2);
    sa->p = sb;
    sb->p = sa;
    auto ss = sa->p.lock();
    std::cout << ss.use_count() << "\n";

    auto *raw_ptr = sa.get();
    auto fsp1 = raw_ptr->shared_from_this();
    auto fsp2 = raw_ptr->shared_from_this();
    std::cout << sa.use_count() << "\n";
}

int main() {
    test_shared();
    std::cout << "\n\n\n";
    test_weak();
    std::cout << "\n\n\n";
    test_enable_from();
}
