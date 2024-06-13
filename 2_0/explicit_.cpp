#include <iostream>

class P {
public:
    P() = default;

    P(int a) {
        std::cout << "P(int a) \n";
    }

    P(int a, int b) {
        std::cout << "P(int a,int b) \n";
    }

    P(std::initializer_list<int>) {
        std::cout << "std::initializer_list<int> \n";
    }

    explicit P(int a, int b, int c) {
        std::cout << "explict P(int a,int b,int c)\n";
    }

    explicit operator bool() const {
        return true;
    }

public:
};

int main() {
    // 构造函数
    P p1(1, 2);
    // 初始化列表构造
    P p2{1, 2, 3, 4, 5};
    // 三参数构造
    P p3(2, 3, 4);

    // 多参数转换
    P p4 = {1, 2};
    P p5 = {1, 2, 3, 4, 5, 6};
    P p6 = {1, 2, 4};

    // (1,2) 其实是逗号表达式，最终会返回2
    // (1, 2, 3, 4, 5, 6) 其实是逗号表达式，最终会返回6
    // (1, 2, 4) 其实是逗号表达式，最终会返回4
    P p7 = (1, 2);
    P p8 = (1, 2, 3, 4, 5, 6);
    P p9 = (1, 2, 4);

    // 隐式转换
    P p10 = 25;

    P p;
    if (p) { // 错误，无法进行隐式转换
        std::cout << "P is true " << "\n";
    }
    if (static_cast<bool>(p)) { // 正确，显式转换
        std::cout << "P is true\n";
    }

    return 0;
}
