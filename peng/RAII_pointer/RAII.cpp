#include <iostream>
#include <fstream>
#include <stdexcept>

class RAIITest
{
private:
    
public:
    RAIITest(){
        std::cout << "调用了构造函数" << std::endl;
    }

    ~RAIITest(){
        std::cout << "调用了析构函数" << std::endl;
    }

    void fun(){
        std::cout << "fun" << std::endl;
    }
};

// 异常安全 (exception-safe)
// C++标准保证当异常发生时，会调用已创建对象的析构函数（自动够掉函数，所以异常安全），因此C++中没有finally语句
void test(){
    std::ofstream fout("a.txt");
    fout << "有一种病\n";
    // 执行到这里，会自动析构fout对象
    throw std::runtime_error("中道蹦粗");
    fout << "叫 java\n";  // 执行完上面的一句就结束了，线程
}

void test2(){
    RAIITest fout;
    fout.fun();
    // 执行到这里，会自动析构fout对象,下面抛出异常了
    throw std::runtime_error("中道蹦粗");
    fout.fun();  
}

int main()
{
    try
    {
        test2();
    }
    catch(const std::exception& e)
    {
        std::cerr << "捕获异常： " << e.what() << std::endl;
    }
    return 0; 
}