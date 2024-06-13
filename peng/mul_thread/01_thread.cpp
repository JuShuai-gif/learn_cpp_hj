#include <iostream>
#include <thread>
#include <string>

void download(std::string file) {
    for (int i = 0; i < 10; ++i) {
        std::cout << "Downloading" << file << "(" << i * 10 << "%)..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << "Download complete: " << file << std::endl;
}

void interact() {
    std::string name;
    std::cin >> name;
    std::cout << "Hi, " << name << std::endl;
}

void myfunc() {
    std::thread t1([&] {
        download("hello.zip");
    });
    // 退出函数体时，会销毁 t1 线程的句柄(如果没有下面的 t1.join();)
    // 有了下面这句话，就会成功执行，编译
    //t1.join();

    // 调用成员函数detach()分离线程，线程的声明周期不再由当前std::thread对象管理
    // 而是在线程退出以后自动销毁自己
    t1.detach();
}

int main() {
    // 
    myfunc();
    interact();

    return 0;
}