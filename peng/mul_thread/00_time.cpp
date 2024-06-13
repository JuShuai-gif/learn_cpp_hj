#include <iostream>
#include <thread>
#include <chrono>

int main(){
    auto t0 = std::chrono::steady_clock::now();
    for (volatile int i = 0; i < 10000000; ++i)
    {
        
    }
    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;

    using double_ms = std::chrono::duration<double,std::milli>;
    using int_ms = std::chrono::duration<int,std::milli>;

    double d_ms = std::chrono::duration_cast<double_ms>(dt).count();
    int i_ms = std::chrono::duration_cast<double_ms>(dt).count();

    std::cout << "time elapsed(double): " << d_ms << "ms" << std::endl;
    std::cout << "time elapsed(int): " << i_ms << "ms" << std::endl;

    // milliseconds表示毫秒
    // microseconds表示微秒
    // seconds表示秒
    // 表示让当前线程睡眠400ms
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // 表示让当前线程睡眠至当前时间+400ms，其实这和上面这句是一样的
    auto t = std::chrono::steady_clock::now() + std::chrono::milliseconds(400);
    std::this_thread::sleep_until(t);
    
    return 0;
}


