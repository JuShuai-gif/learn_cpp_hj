#include <iostream>
#include <cstddef>

struct P2 {
    int i;//4
    char c;//1
    char d;//1
    long j;//8
};

int main() {
    std::cout << "Offset of i: " << offsetof(P2, i) << " bytes" << std::endl;
    std::cout << "Offset of c: " << offsetof(P2, c) << " bytes" << std::endl;
    std::cout << "Offset of d: " << offsetof(P2, d) << " bytes" << std::endl;
    std::cout << "Offset of j: " << offsetof(P2, j) << " bytes" << std::endl;
    std::cout << "Size of P2 struct: " << sizeof(P2) << " bytes" << std::endl;
    std::cout << "Alignment of P2 struct: " << alignof(P2) << " bytes" << std::endl;
    return 0;
}