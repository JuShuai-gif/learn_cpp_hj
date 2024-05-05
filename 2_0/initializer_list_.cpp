#include <iostream>

class P
{
public:
    P(int a,int b)
    {
        std::cout << "P(int,int),a = " << a << ",b = " << b << std::endl;
    }
public:
    /*
    P(std::initializer_list<int> initlist)
    {
        std::cout << "P(initializer_list<int>),values = ";
        for (auto i : initlist)
        {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        
    }
    */
};

int main()
{
    P p(1,2);
    //P q{1,2,3,4,5,6};
    // 如果将初始化列表删除的话，那么只会调用 P(int a,int b) 这种情况
    P s = {4,5};

    return 0;
}
