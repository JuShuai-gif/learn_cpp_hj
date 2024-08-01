#pragma once

// 包含两个函数 construct,destroy
// construct : 负责对象的构造
// destroy: 负责对象的析构

#include <new>

#include "type_traits.h"
#include "iterator.h"

namespace mystl {

template <class Ty>
void construct(Ty *ptr) {
    // ::new 使用全局作用域的 new 运算符，避免与类或其他命名空间中的 new 运算符混淆
    // ((void*)ptr) 指向对象应该被构造的位置的指针
    ::new ((void *)ptr) Ty();
}

// 单参数构造函数的重载版本
template <class Ty1, class Ty2>
void construct(Ty1 *ptr, const Ty2 &value) {
    ::new ((void *)ptr) Ty1(value);
}

// 可变参数模版的重载版本
template <class Ty, class... Args>
void construct(Ty *ptr, Args &&...args) {
    ::new ((void *)ptr) Ty(mystl::forward<Args>(args)...);
}

// destroy 将对象析构
// 对于平凡可销毁的类型，不需要做任何事情
template <class Ty>
void destroy_one(Ty *, std::true_type) {
}

template <class Ty>
void destroy_one(Ty *pointer, std::false_type) {
    if (pointer != nullptr) {
        pointer->~Ty();// 调用对象的析构函数
    }
}

// 对于平凡可销毁的类型，不需要做任何事情
template <class ForwardIter>
void destroy_cat(ForwardIter, ForwardIter, std::true_type) {
}


template <class ForwardIter>
void destroy_cat(ForwardIter first, ForwardIter last, std::false_type) {
    for (; first != last; ++first)
        destroy(&*first);// 递归调用 destroy 来销毁每个对象
}

template <class Ty>
void destroy(Ty *pointer) {
    destroy_one(pointer, std::is_trivially_destructible<Ty>{});
}

template <class ForwardIter>
void destroy(ForwardIter first, ForwardIter last) {
    destroy_cat(first, last, std::is_trivially_destructible<typename iterator_traits<ForwardIter>::value_type>{});
}
} // namespace mystl
