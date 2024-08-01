#pragma once

// 这个文件包含一些通用工具，包括 move、forward、swap 等函数 以及 pair 等

#include <cstddef>
#include "type_traits.h"

namespace mystl {

// move
template <class T>
typename std::remove_reference<T>::type &&move(T &&arg) noexcept {
    // std::remove_reference<T>::type：移除 T 的引用部分，获取原始类型
    return static_cast<typename std::remove_reference<T>::type &&>(arg);
}

// forward 实现完美转发，完美转发是一种保留函数参数值类别(左值或右值)
// 两个重载版本，用于处理左值和右值引用
template <class T>
T &&forward(typename std::remove_reference<T>::type &arg) noexcept {
    return static_cast<T &&>(arg);
}

template <class T>
T &&forward(typename std::remove_reference<T>::type &&arg) noexcept {
    static_assert(!std::is_lvalue_reference<T>::value, "bad forward");
    return static_cast<T &&>(arg);
}

// swap
template <class Tp>
void swap(Tp &lhs, Tp &rhs) {
    auto tmp(mystl::move(lhs));
    lhs = mystl::move(rhs);
    rhs = mystl::move(tmp);
}

template <class ForwardIter1, class ForwardIter2>
ForwardIter2 swap_range(ForwardIter1 first1, ForwardIter1 last1, ForwardIter2 first2) {
    for (; first1 != last1; ++first1, (void)++first2)
        mystl::swap(*first1, *first2);
    return first2;
}

// 范围元素交换
template <class Tp, size_t N>
void swap(Tp (&a)[N], Tp (&b)[N]) {
    mystl::swap_range(a, a + N, b);
}

// -------------------------------------------------------------------
// pair

// 结构体模板 : pair
// 两个模板参数分别表示两个数据的类型
// 用 first 和 second 来分别取出第一个数据和第二个数据
template <class Ty1, class Ty2>
struct pair {
    // 定义两个元素的类型别名
    typedef Ty1 first_type;
    typedef Ty2 second_type;

    first_type first;   // 保存第一个数据
    second_type second; // 保存第二个数据

    // 默认构造函数
    template <class Other1 = Ty1, class Other2 = Ty2,
              typename = typename std::enable_if<
                  std::is_default_constructible<Other1>::value && std::is_default_constructible<Other2>::value, void>::type>
    constexpr pair() :
        first(), second() {
    }

    // 隐式构造
    template <class U1 = Ty1, class U2 = Ty2,
              typename std::enable_if<
                  std::is_copy_constructible<U1>::value && std::is_copy_constructible<U2>::value && std::is_convertible<const U1 &, Ty1>::value && std::is_convertible<const U2 &, Ty2>::value, int>::type = 0>
    constexpr pair(const Ty1 &a, const Ty2 &b) :
        first(a), second(b) {
    }

    // 显式构造
    template <class U1 = Ty1, class U2 = Ty2,
              typename std::enable_if<
                  std::is_copy_constructible<U1>::value && std::is_copy_constructible<U2>::value && (!std::is_convertible<const U1 &, Ty1>::value || !std::is_convertible<const U2 &, Ty2>::value), int>::type = 0>
    explicit constexpr pair(const Ty1 &a, const Ty2 &b) :
        first(a), second(b) {
    }

    pair(const pair &rhs) = default;
    pair(pair &&rhs) = default;

    // 隐式构造其它类型
    template <class Other1, class Other2,
              typename std::enable_if<
                  std::is_constructible<Ty1, Other1>::value && std::is_constructible<Ty2, Other2>::value && std::is_convertible<Other1 &&, Ty1>::value && std::is_convertible<Other2 &&, Ty2>::value, int>::type = 0>
    constexpr pair(Other1 &&a, Other2 &&b) :
        first(mystl::forward<Other1>(a)),
        second(mystl::forward<Other2>(b)) {
    }

    // 显式构造其它类型
    template <class Other1, class Other2,
              typename std::enable_if<
                  std::is_constructible<Ty1, Other1>::value && std::is_constructible<Ty2, Other2>::value && (!std::is_convertible<Other1, Ty1>::value || !std::is_convertible<Other2, Ty2>::value), int>::type = 0>
    explicit constexpr pair(Other1 &&a, Other2 &&b) :
        first(mystl::forward<Other1>(a)),
        second(mystl::forward<Other2>(b)) {
    }

    // 隐式构造其它pair
    template <class Other1, class Other2,
              typename std::enable_if<
                  std::is_constructible<Ty1, const Other1 &>::value && std::is_constructible<Ty2, const Other2 &>::value && std::is_convertible<const Other1 &, Ty1>::value && std::is_convertible<const Other2 &, Ty2>::value, int>::type = 0>
    constexpr pair(const pair<Other1, Other2> &other) :
        first(other.first),
        second(other.second) {
    }

    // 显式构造其它pair
    template <class Other1, class Other2,
              typename std::enable_if<
                  std::is_constructible<Ty1, const Other1 &>::value && std::is_constructible<Ty2, const Other2 &>::value && (!std::is_convertible<const Other1 &, Ty1>::value || !std::is_convertible<const Other2 &, Ty2>::value), int>::type = 0>
    explicit constexpr pair(const pair<Other1, Other2> &other) :
        first(other.first),
        second(other.second) {
    }

    // 隐式构造其它pair
    template <class Other1, class Other2,
              typename std::enable_if<
                  std::is_constructible<Ty1, Other1>::value && std::is_constructible<Ty2, Other2>::value && std::is_convertible<Other1, Ty1>::value && std::is_convertible<Other2, Ty2>::value, int>::type = 0>
    constexpr pair(pair<Other1, Other2> &&other) :
        first(mystl::forward<Other1>(other.first)),
        second(mystl::forward<Other2>(other.second)) {
    }

    // 显式构造其它pair
    template <class Other1, class Other2,
              typename std::enable_if<
                  std::is_constructible<Ty1, Other1>::value && std::is_constructible<Ty2, Other2>::value && (!std::is_convertible<Other1, Ty1>::value || !std::is_convertible<Other2, Ty2>::value), int>::type = 0>
    explicit constexpr pair(pair<Other1, Other2> &&other) :
        first(mystl::forward<Other1>(other.first)),
        second(mystl::forward<Other2>(other.second)) {
    }

    // 拷贝赋值
    pair &operator=(const pair &rhs) {
        if (this != &rhs) {
            first = rhs.first;
            second = rhs.second;
        }
        return *this;
    }

    // 移动赋值
    pair &operator=(pair &&rhs) {
        if (this != &rhs) {
            first = mystl::move(rhs.first);
            second = mystl::move(rhs.second);
        }
        return *this;
    }

    // copy assign for other pair
    template <class Other1, class Other2>
    pair &operator=(const pair<Other1, Other2> &other) {
        first = other.first;
        second = other.second;
        return *this;
    }

    // move assign for other pair
    template <class Other1, class Other2>
    pair &operator=(pair<Other1, Other2> &&other) {
        first = mystl::forward<Other1>(other.first);
        second = mystl::forward<Other2>(other.second);
        return *this;
    }

    ~pair() = default;

    void swap(pair &other) {
        if (this != &other) {
            mystl::swap(first, other.first);
            mystl::swap(second, other.second);
        }
    }
};

// 重载比较操作符
template <class Ty1, class Ty2>
bool operator==(const pair<Ty1, Ty2> &lhs, const pair<Ty1, Ty2> &rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class Ty1, class Ty2>
bool operator<(const pair<Ty1, Ty2> &lhs, const pair<Ty1, Ty2> &rhs) {
    return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
}

template <class Ty1, class Ty2>
bool operator!=(const pair<Ty1, Ty2> &lhs, const pair<Ty1, Ty2> &rhs) {
    return !(lhs == rhs);
}

template <class Ty1, class Ty2>
bool operator>(const pair<Ty1, Ty2> &lhs, const pair<Ty1, Ty2> &rhs) {
    return rhs < lhs;
}

template <class Ty1, class Ty2>
bool operator<=(const pair<Ty1, Ty2> &lhs, const pair<Ty1, Ty2> &rhs) {
    return !(rhs < lhs);
}

template <class Ty1, class Ty2>
bool operator>=(const pair<Ty1, Ty2> &lhs, const pair<Ty1, Ty2> &rhs) {
    return !(lhs < rhs);
}

// 重载 mystl 的 swap
template <class Ty1, class Ty2>
void swap(pair<Ty1, Ty2> &lhs, pair<Ty1, Ty2> &rhs) {
    lhs.swap(rhs);
}

// 全局函数，让两个数据成为一个 pair
template <class Ty1, class Ty2>
pair<Ty1, Ty2> make_pair(Ty1 &&first, Ty2 &&second) {
    return pair<Ty1, Ty2>(mystl::forward<Ty1>(first), mystl::forward<Ty2>(second));
}

} // namespace mystl