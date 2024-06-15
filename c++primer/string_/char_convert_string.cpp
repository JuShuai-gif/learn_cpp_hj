#include <iostream>
#include <string>

int main() {
    // 字符串字面值转换为std::string
    const char* c_str = "Hello, World!";
    std::string str = c_str;
    std::cout << "std::string: " << str << std::endl;

    // std::string转换为C风格字符串
    const char* converted_c_str = str.c_str();
    std::cout << "C风格字符串: " << converted_c_str << std::endl;

    return 0;
}
