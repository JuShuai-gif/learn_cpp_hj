#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called!" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called!" << std::endl;
    }
};

int main() {
    // 使用 new 分配内存并调用构造函数
    MyClass* obj = new MyClass();  // 动态分配 MyClass 对象
    delete obj;  // 使用 delete 释放内存并调用析构函数

    // 使用 new[] 分配动态数组
    MyClass* arr = new MyClass[2];  // 动态分配 MyClass 数组
    delete[] arr;  // 使用 delete[] 释放数组内存并调用析构函数

    // new内存分配失败时会抛出 std::bad_alloc 异常

    return 0;
}
