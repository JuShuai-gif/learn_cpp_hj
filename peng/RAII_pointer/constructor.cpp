#include <iostream>
#include <string>
#include <vector>

class constructor {
private:
    int num{15};

public:
    constructor() = delete;
    constructor(int nnn) :
        num(nnn) {
    }
};

class Pig {
private:
    std::string m_name;
    int m_weight;

public:
    // 构造函数：无参数(使用初始化表达式)
    //  1. 假如类成员为const和引用
    //  2. 假如类成员没有无参构造函数
    //  3. 避免重复初始化，更高效
    Pig() :
        m_name("佩奇"), m_weight(15) {
        std::cout << "m_name: " << m_name << std::endl;
        std::cout << "m_weight: " << m_weight << std::endl;
    }
};

class Person {
public:
    std::string p_name_{};
    int age_{};
    const int id_;

public:
    Person() = default;

    Person(std::string p_name, int age) :
        p_name_(p_name), age_(age), id_(15) {
    }

    ~Person() {
    }
};

void test_copy() {
    std::vector<int> v1(10);
    std::vector<int> v2(200);

    v1 = v2; // 拷贝赋值 O(n)

    std::cout << "after copy: " << std::endl;
    std::cout << "v1 length: " << v1.size() << std::endl;
    std::cout << "v2 length: " << v2.size() << std::endl;
}

void test_move() {
    std::vector<int> v1(10);
    std::vector<int> v2(200);

    v1 = std::move(v2); // 拷贝赋值 O(n)

    std::cout << "after move: " << std::endl;
    std::cout << "v1 length: " << v1.size() << std::endl;
    std::cout << "v2 length: " << v2.size() << std::endl;
}

void test_swap() {
    std::vector<int> v1(10);
    std::vector<int> v2(200);

    std::swap(v1, v2); // 交换两者 O(1)

    std::cout << "after swap: " << std::endl;
    std::cout << "v1 length: " << v1.size() << std::endl;
    std::cout << "v2 length: " << v2.size() << std::endl;
}

int main() {
    Person person("person", 15);
    std::cout << person.age_ << std::endl;
    test_copy();
    test_move();
    test_swap();
    return 0;
}