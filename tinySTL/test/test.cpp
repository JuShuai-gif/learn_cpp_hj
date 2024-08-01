#include <iostream>
#include <iterator>
#include <vector>
#include "iterator.h"

using namespace mystl;

// 示例迭代器类型
struct MyInputIterator {
    typedef mystl::input_iterator_tag iterator_category;
    typedef int value_type;
    typedef int* pointer;
    typedef int& reference;
    typedef std::ptrdiff_t difference_type;
};

struct NotAnIterator {};

int main() {
   // 使用 has_iterator_cat_of 检查 MyInputIterator 的 iterator_category 是否为 input_iterator_tag
    std::cout << std::boolalpha;
    std::cout << "MyInputIterator is input iterator: "
              << mystl::has_iterator_cat_of<MyInputIterator, mystl::input_iterator_tag>::value << std::endl;
    std::cout << "MyInputIterator is output iterator: "
              << mystl::has_iterator_cat_of<MyInputIterator, mystl::output_iterator_tag>::value << std::endl;

    // 使用 has_iterator_cat_of 检查 NotAnIterator 的 iterator_category 是否为 input_iterator_tag
    std::cout << "NotAnIterator is input iterator: "
              << mystl::has_iterator_cat_of<NotAnIterator, mystl::input_iterator_tag>::value << std::endl;

    // 使用 has_iterator_cat_of 检查原生指针的 iterator_category 是否为 random_access_iterator_tag
    std::cout << "int* is random access iterator: "
              << mystl::has_iterator_cat_of<int*, mystl::random_access_iterator_tag>::value << std::endl;

    return 0;
}
