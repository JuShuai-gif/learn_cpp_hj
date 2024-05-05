#include <iostream>
#include <chrono>
int main() {
    int num = 100000;

    auto start_endl = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num; ++i) {
        std::cout << "Hello" << std::endl;
    }
    auto fin_endl = std::chrono::high_resolution_clock::now();
    auto duration_endl = std::chrono::duration_cast<std::chrono::microseconds>(fin_endl - start_endl);

    
    auto start_newline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num; ++i) {
        std::cout << "Hello \n";
    }
    auto fin_newline = std::chrono::high_resolution_clock::now();
    auto duration_newline = std::chrono::duration_cast<std::chrono::microseconds>(fin_newline - start_newline);
    std::cout << "Time with 'endl': " << duration_endl.count() << " microseconds\n";
    std::cout << "Time with '\\n': " << duration_newline.count() << " microseconds\n";

    return 0;
}