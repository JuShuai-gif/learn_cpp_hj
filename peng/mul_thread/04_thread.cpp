#include <iostream>
#include <thread>
#include <string>
#include <vector>

void do_something(int &i) {
    std::cout << "do_some_work " << i << std::endl;
}

void do_something_else(int &i) {
    std::cout << "do_something_else " << i << std::endl;
}

struct func {
    int &i;
    func(int &i_) :
        i(i_) {
    }
    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
            do_something(i); // 1 潜在访问隐患：悬空引用
        }
    }
};
void oops() {
    int some_local_state = 4;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach(); // 2 不等待线程结束
} // 3 新线程可能还在运行

int main() {
    oops();
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    return 0;
}
