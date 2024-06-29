#include <iostream>

struct func_printnum_t
{
    func_printnum_t(int x_val, int y_val) : x(x_val), y(y_val) {}
    void operator()(int i)const{
        printf("Numbers are: %d, %d\n",x,y);
    }

    int x;
    int y;
};

template <class Fun>
void repeattwice(Fun const& func){
    func(12);
    func(12);
}


int main(){
 int n{},m{};
        // 正确初始化并调用 repeattwice
    func_printnum_t func1(n, m);
    repeattwice(func1); // 传递完整初始化的对象

    repeattwice(func_printnum_t(23,46));

    int x{24},y{42};

    repeattwice([&](int i){
        printf("#%d Number are: %d, %d \n",i,x,y);
        x = 12;
        y = 13;
    });

    printf("Number are: %d, %d \n",x,y);
    return 0;
}