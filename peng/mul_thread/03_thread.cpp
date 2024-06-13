#include <iostream>
#include <thread>
#include <string>
#include <vector>

void do_something() {
    std::cout << "do_some_work" << std::endl;
}

void do_something_else() {
    std::cout << "do_something_else" << std::endl;
}

class background_task {
public:
    void operator()() const {
        do_something();
        do_something_else();
    }
};

int main() {
    background_task f;
    std::thread my_thread(f);
    // 这种写法是错误的，它会将下面当做一个函数定义，而不是一个std::thread对象
    std::thread my_thread2(background_task());

    // 下面是替代方案
    std::thread my_thread3((background_task()));
    std::thread my_thread4{background_task()};

    // 使用lambda也可以解决这个问题
    std::thread my_thread5([] {
        do_something();
        do_something_else();
    });

    my_thread.join();
    my_thread3.join();
    my_thread4.join();
    my_thread5.join();
    return 0;
}
