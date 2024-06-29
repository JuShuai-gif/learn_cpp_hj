#include <iostream>

// 只打印函数名
// #define LOG(x) (std::cout << __FILE__ << ":" << __LINE__ << ": " \
// << __func__ << "(): " << (x) << std::endl)

// 打印函数签名
#define LOG(x) (std::cout << __FILE__ << ":" << __LINE__ << ": " \
<< __PRETTY_FUNCTION__ << ": " << (x) << std::endl)

template<class T>
void func(T a){
    LOG("inthefunc(T)");
}

void func(){
    LOG("inthefunc()");
}

int main(){
    func();
    // 调用模版的话，也可以把模版类型也给出
    func(3);

    std::cout << __FILE__ << std::endl;
    LOG(12);
    
    std::cout << __amd64__ << std::endl;

    std::cout << __DATE__ << std::endl;

    std::cout << __LINE__ << std::endl;

    return 0;
}