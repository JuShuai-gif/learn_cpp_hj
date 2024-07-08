#include <iostream>
// gcc -fomit-frame-pointer -fverbose-asm -S test1.cpp -o /home/robot/code/c++/learn_cpp_hj/peng/SIMD/main2.S
int func(){
    return 42;
}

int func2(int a,int b,int c,int d){
    return a;
}

long long func3(long long a,long long b){
    return a *b;
}

/*int main(){
    func();
    return 0;
}*/