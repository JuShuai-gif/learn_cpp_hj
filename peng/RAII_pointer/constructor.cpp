#include <iostream>
#include <string>

class constructor
{
private:
    int num{15};
public:
    constructor() = delete;
    constructor(int nnn):num(nnn){}
};

class Pig
{
private:
    std::string m_name;
    int m_weight;

public:
    // 构造函数：无参数(使用初始化表达式)
    //  1. 假如类成员为const和引用
    //  2. 假如类成员没有无参构造函数
    //  3. 避免重复初始化，更高效
    Pig():m_name("佩奇"),m_weight(15)
    {
        std::cout << "m_name: " << m_name << std::endl;
        std::cout << "m_weight: " << m_weight << std::endl;
    }
};

int main()
{
    Pig pig;
    constructor con(15);
    return 0;
}