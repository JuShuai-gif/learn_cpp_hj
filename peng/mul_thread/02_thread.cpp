#include <iostream>
#include <thread>
#include <string>
#include <vector>

void download(std::string file) {
    for (int i = 0; i < 10; ++i) {
        std::cout << "Downloading" << file << "(" << i * 10 << "%)..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << "Download complete: " << file << std::endl;
}

class ThreadPool
{
public:
    std::vector<std::thread> m_pool;

public:
    void push_back(std::thread thr){
        m_pool.push_back(std::move(thr));
    }

    
    ~ThreadPool(){
        for (auto &t : m_pool){ // main函数退出后会自动调用
            t.join();           // 等待池里的线程全部执行完毕
        }
    }
};

ThreadPool tpool;

void myfunc(){
    std::thread t1([&]{
        download("hello.zip");
    });
    tpool.push_back(std::move(t1));
}

void interact() {
    std::string name;
    std::cin >> name;
    std::cout << "Hi, " << name << std::endl;
}

int main(){
    myfunc();
    interact();
    return 0;
}



