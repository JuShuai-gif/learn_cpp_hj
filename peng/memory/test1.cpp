#include <ios>
#include <iostream>
#include <chrono>

int main() {
    const int kSize = 100000;
    const int kRepeat = 10000;
	// 对齐
    alignas(4) char buffer[sizeof(int) * (kSize + 1)];

    int* aligned_data = reinterpret_cast<int*>(buffer);
    int* unaligned_data = reinterpret_cast<int*>(buffer + 1);

    // Initialize data
    for (int i = 0; i < kSize; ++i) {
        aligned_data[i] = i;
        unaligned_data[i] = i;
    }
    // 用来展示不同地址对齐
    std::cout << std::hex << std::showbase << \
        "aligned_data address: " << &aligned_data[0] << "\n" \
        "unaligned_data address: " << &unaligned_data[0] << "\n";
	// 回到标准的 std::dec
    std::cout.unsetf(std::ios_base::basefield);
    // Measure time for aligned access
    auto start_aligned = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < kRepeat; ++r) {
        int sum = 0;
        for (int i = 0; i < kSize; ++i) {
            sum += aligned_data[i];
        }
    }
    auto end_aligned = std::chrono::high_resolution_clock::now();

    // Measure time for unaligned access
    auto start_unaligned = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < kRepeat; ++r) {
        int sum = 0;
        for (int i = 0; i < kSize; ++i) {
            sum += unaligned_data[i];
        }
    }
    auto end_unaligned = std::chrono::high_resolution_clock::now();

    auto aligned_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_aligned - start_aligned).count();
    auto unaligned_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_unaligned - start_unaligned).count();

    std::cout << "Time for aligned access: " << aligned_duration << " microseconds" << std::endl;
    std::cout << "Time for unaligned access: " << unaligned_duration << " microseconds" << std::endl;

    return 0;
}