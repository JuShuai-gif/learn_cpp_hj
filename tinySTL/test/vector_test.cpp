#include "vector.h"
#include <iostream>

template <class T>
void print_test() {
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    for (auto &i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    mystl::vector<int> v1;
    mystl::vector<int> v2(10);
    mystl::vector<int> v3(10, 1);
    mystl::vector<int> v4(a, a + 5);
    mystl::vector<int> v5(v2);
    mystl::vector<int> v6(std::move(v2));
    mystl::vector<int> v7{1, 2, 3, 4, 5, 6, 7, 8, 9};
    mystl::vector<int> v8, v9, v10;
    for (auto &i : v3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    

    return 0;
}