#pragma once

#include <type_traits>

namespace mystl {

template <class T, T v>
struct m_integral_constant {
    static constexpr T value = v;
};

template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;

typedef m_bool_constant<true> m_true_type;
typedef m_bool_constant<false> m_false_type;

template <class T1, class T2>
struct pair;
// --- forward declaration end

template <class T>
struct is_pair : m_false_type {};

template <class T1, class T2>
struct is_pair<pair<T1, T2>> : m_true_type {};
} // namespace mystl
