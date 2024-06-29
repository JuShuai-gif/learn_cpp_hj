
#include <iostream>

class Base {
public:
    virtual void show(int x = 10) const { // 基类中的默认参数
        std::cout << "Base show: " << x << std::endl;
    }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void show(int x = 20) const override { // 派生类中的默认参数
        std::cout << "Derived show: " << x << std::endl;
    }
};

int main() {
    Base base;
    Derived derived;
    Base* basePtr = &derived;

    base.show(); // 输出 "Base show: 10"
    derived.show(); // 输出 "Derived show: 20"
    basePtr->show(); // 输出 "Derived show: 10"

    return 0;
}
