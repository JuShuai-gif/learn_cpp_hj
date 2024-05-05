#include <iostream>
#include <vector>
#include <algorithm>

int sum = 0;
void fun(int v){
    sum += v;
}

int main()
{
    // 判断C++标准
    std::cout << __cplusplus << std::endl;

    // Vector的一种赋值方式  C++98
    std::vector<int> v1(4);
    v1[0] = 0;
    v1[1] = 1;
    v1[2] = 2;
    v1[3] = 3;

    for (size_t i = 0; i < v1.size(); ++i)
    {
        std::cout << v1[i] << std::endl;
    }

    // 下面这两种方式都是C++11之后的
    std::vector<int> v2(4,4);
    for (auto v:v2)
    {
        std::cout << v << std::endl;
    }

    std::vector<int> v3{1,2,3,4,56};
    std::for_each(v3.begin(),v3.end(),fun);
    std::cout << "sum: " << sum << std::endl;

    // 使用lambda表达式,C++14允许使用auto 自动推断类型
    int s = 0;
    std::vector<int> v4 = {1,2,3,4,5};
    std::for_each(v4.begin(),v4.end(),[&](auto v){
        s += v;
    });
    std::cout << "s: " << s << std::endl;

    // c++17 允许std::vector不用模版参数即可推断  CATD类型推断 
    /*
    std::vector v = {4,3,2,1};
    int m = 0;
        std::for_each(v4.begin(),v4.end(),[&](auto v){
        m += v;
    });
    std::cout << "m: " << m << std::endl;
    */


    std::vector<int> vvv;
    std::cout << "vvv.size() " << vvv.size() << std::endl;
    std::cout << "vvv.capacity(): " << vvv.capacity() << std::endl;


    std::vector<int> vvvv;
    vvvv.push_back(1);vvvv.push_back(2);vvvv.push_back(1);vvvv.push_back(1);vvvv.push_back(1);
    std::cout << "vvvv.size() " << vvvv.size() << std::endl;
    std::cout << "vvvv.capacity(): " << vvvv.capacity() << std::endl;

    std::vector<int> vv(2);//限定2个空间就是两个空间
    vv[0] = 4;
    vv[1] = 3;
    vv.push_back(2);
    std::cout << "vv.size() " << vv.size() << std::endl;
    std::cout << "vv.capacity(): " << vv.capacity() << std::endl;
    vv.resize(4);

    for (size_t i = 0; i < vv.capacity(); ++i)
    {
        std::cout << vv[i] << std::endl;
    }
    

    return 0;
}
