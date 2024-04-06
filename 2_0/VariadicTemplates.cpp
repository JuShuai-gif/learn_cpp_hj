#include <iostream>

// 打印参数个数
template<class... T>
void f(T... args){
    std::cout << sizeof...(args) << std::endl;
}

// 递归终止函数终止递归
template<class T>
void print(T t){
    std::cout << t << std::endl;
}

template <class T,class... Args>
void print(T head,Args... args){
    std::cout << "参数：" << head << std::endl;
    print(args...);
}

// 通过可变参数，求和
template<class T>
T sum(T t){
    return t;
}
template<class T,typename... Args>
T sum(T first,Args... args){
    return first + sum<T>(args...);
}

// 使用逗号表达式展开参数包
// 终止函数
template<class T>
void printarg(T t){
    std::cout << t << std::endl;
}

template<typename... Args>
void expand(Args... args){
    int arr[] = {(printarg(args),0)...};
    for (size_t i = 0; i < 4; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

// 模版偏特化和递归方式展开参数包
// 前向声明
template<typename... Args>
struct Sum;

// 基本定义
template<typename First,typename... Rest>
struct Sum<First,Rest...>
{
    enum{value = Sum<First>::value + Sum<Rest...>::value};
};

// 递归终止
template<typename Last>
struct Sum<Last>
{
    enum{value = sizeof(Last)};
};

// 泛化与特化
template<class T>
void print1(T t){
    std::cout << t << std::endl;
}

template <typename T,typename... Types>
void print1(const T& firstArg,const Types&... args){
    std::cout << "const T& firstArg,const Types&... args" << std::endl;
    std::cout << firstArg << std::endl;
    print1(args...);
}

template<typename... Types>
void print1(const Types&... args){
    std::cout << "const Types&... args" << std::endl;
    print1(args...);
}


int main(){
    std::cout << "******** 打印参数个数 *********" << std::endl;
    f();
    f(1,2,3);
    f(1,2,3,4,5,6," ");

    std::cout << "******** 递归参数调用 *********" << std::endl;
    print(1,2,3,4);

    std::cout << "******** 递归求和调用 *********" << std::endl;
    double s{};
    std::cout << "sum: " << sum(s,1,2,3,4,5) << std::endl;

    std::cout << "******** 逗号展开参数列表 *********" << std::endl;
    expand(1,2,3,4);

    std::cout << "******** 泛化与特化 *********" << std::endl;
    print1(1,2,3,4);

    return 0;
}