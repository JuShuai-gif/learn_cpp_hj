#pragma once

#include <stdexcept>
#include <cassert>

namespace mystl {
// 宏用于在调试模式下进行断言检查。assert是一个标准库函数
#define MYSTL_DEBUG(expr) \
    assert(expr)

#define THROW_LENGTH_ERROR_IF(expr, what) \
    if ((expr)) throw std::length_error(what)

#define THROW_OUT_OF_RANGE_IF(expr, what) \
    if ((expr)) throw std::out_of_range(what)

#define THROW_RUNTIME_ERROR_IF(expr, what) \
    if ((expr)) throw std::runtime_error(what)

} // namespace mystl
