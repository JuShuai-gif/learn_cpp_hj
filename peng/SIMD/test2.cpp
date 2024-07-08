#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>   // for std::iota
#include <algorithm> // for std::shuffle
#include <random>    // for std::default_random_engine
#include <iomanip>   // for std::fixed and std::setprecision

void processData(const std::vector<int> &data) {
    int sum = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i];
    }
}

void processOptimizedData(const std::vector<int> &data) {
    int sum = 0;
    size_t dataSize = data.size();
    size_t blockSize = 32 / sizeof(int); // 根据缓存行大小选择合适的块大小

    for (size_t i = 0; i < dataSize; i += blockSize) {
        for (size_t j = i; j < i + blockSize && j < dataSize; ++j) {
            sum += data[j];
        }
    }
}

int main() {
    const size_t dataSize = 100000000; // 1千万个元素
    std::vector<int> data(dataSize);

    // Fill data with sequential values and shuffle to avoid any accidental optimization by the compiler
    std::iota(data.begin(), data.end(), 0);
    std::shuffle(data.begin(), data.end(), std::default_random_engine());

    // Measure time for processData
    auto start = std::chrono::high_resolution_clock::now();
    processData(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Time taken by processData: " << duration.count() << " seconds" << std::endl;

    // Measure time for processOptimizedData
    start = std::chrono::high_resolution_clock::now();
    processOptimizedData(data);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken by processOptimizedData: " << duration.count() << " seconds" << std::endl;

    return 0;
}
