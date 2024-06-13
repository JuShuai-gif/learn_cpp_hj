#include <thread>
#include <iostream>

void f(int i, std::string const &s) {
    std::cout << "i: " << i << "s: " << s << std::endl;
}

// 下面的函数会崩溃
/*
函数f需要一个 std::string 对象作为第二个参数，但这里使用的是字符串的字面值，也就是 char const * 类型。
之后，在线程的上下文中完成字面值向 std::string 对象的转化。
有可能线程t已经启动了，但是buffer没有转化完成，这时buffer就是一个错误值(乱码)

在下面加个循环可以避免这个问题
*/
void oops(int some_param) {
    std::cout << "进入oops函数" << std::endl;

    char buffer[1024]; // 1
    sprintf(buffer, "%i", some_param);
    std::thread t(f, 3, buffer); // 2
    t.detach();

    for (size_t i = 0; i < 1000000; i++) {
        std::cout << "进入oops函数" << std::endl;
    }
}

void not_oops(int some_param)
{
    std::cout << "进入not_oops函数" << std::endl;
    char buffer[1024];
    sprintf(buffer, "%i", some_param);
    std::thread t(f, 3, std::string(buffer)); // 使用std::string，避免悬垂指针
    t.detach();
}

int main() {
    not_oops(100);
    return 0;
}
