#include <iostream>

class A {};

class B {
    virtual void Fun() {
    }
};

class C {
    static int a;
};

class D{
    int a;
};

class E{
    static int a;
    int b;
};

int main() {
    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;
    std::cout << sizeof(C) << std::endl;
    std::cout << sizeof(D) << std::endl;
    std::cout << sizeof(E) << std::endl;
    return 0;
}
