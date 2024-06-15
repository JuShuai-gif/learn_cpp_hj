// 定义了用于读写流的基本类型
#include <iostream>
#include <string>
// 定义了读写命名文件的类型
#include <fstream>
// 定义了读写内存string对象的类型
#include <sstream>
#include <vector>
#include <thread>

#include <mutex>
#include <condition_variable>
// 定义共享变量和同步工具
std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;
std::string sharedData;

void writeToFile(const std::string &filename) {
    // 打开文件用于写入
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing" << std::endl;
        return;
    }

    // 写入数据
    {
        std::lock_guard<std::mutex> lock(mtx);
        sharedData = "Hello, this is a test.";
        dataReady = true;
    }

    // 通知读取线程
    cv.notify_one();
    
    // 关闭文件
    file.close();
}

void readFromFile(const std::string &filename) {
    // 等待数据准备好
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return dataReady; });

    // 打开文件用于读取
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for reading" << std::endl;
        return;
    }

    // 读取文件内容
    std::string fileContent;
    file.seekg(0, std::ios::end);
    fileContent.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    fileContent.assign((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());

    // 输出读取到的内容
    std::cout << "File content: " << fileContent << std::endl;

    // 关闭文件
    file.close();
}

int main() {
    const std::string filename = "test.txt";

    // 创建写入和读取线程
    std::thread writer(writeToFile, filename);
    std::thread reader(readFromFile, filename);

    // 等待线程完成
    writer.join();
    reader.join();

    return 0;
}

