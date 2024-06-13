#include <thread>
#include <iostream>

void f() {
    while (true) {
        std::cout << " f  函数调用" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

void g() {
    while (true) {
        std::cout << " g  函数调用" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

int main() {
    std::thread t(f);
    std::thread tt(g);
    t.join();
    tt.join();
    return 0;
}
