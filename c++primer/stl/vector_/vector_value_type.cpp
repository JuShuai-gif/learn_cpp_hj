#include <vector>
#include <iostream>
#include <type_traits> // for std::is_same

/*
value_type 提供了一种泛型编程的方法，使得编写与容器无关的代码变得更加容易。
例如，当你编写一个模板函数，希望能够处理不同类型的容器时，可以使用 value_type 来引用容器中的元素类型。

1. value_type 是 C++ 容器类（如 std::vector）的嵌套类型，用于表示容器中存储的元素类型。
2. 使用 value_type 可以使模板代码更加通用和灵活。
3. 通过 typename Container::value_type 可以获取容器中元素的类型，从而编写与容器无关的通用代码。
*/

template <typename Container>
void printContainer(const Container& container) {
    using ValueType = typename Container::value_type;
    for (const ValueType& value : container) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // 通过value_type获取元素类型
    std::vector<int>::value_type val = 10; // 这相当于 int val = 10;

    // 打印容器内容
    printContainer(v); // 输出：1 2 3 4 5
    
    // 检查 value_type 是否正确
    static_assert(std::is_same<std::vector<int>::value_type, int>::value, "Error: value_type is not int");

    return 0;
}
