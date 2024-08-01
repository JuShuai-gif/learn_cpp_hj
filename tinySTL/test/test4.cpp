#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 创建一个包含未排序元素的 vector
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 将 vec 转换为一个最大堆
    std::make_heap(vec.begin(), vec.end());
    std::cout << "After make_heap: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 将一个新元素添加到堆中
    vec.push_back(7);
    std::push_heap(vec.begin(), vec.end());
    std::cout << "After push_heap: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 从堆中移除根元素
    std::pop_heap(vec.begin(), vec.end());
    int root = vec.back();
    vec.pop_back();
    std::cout << "After pop_heap (root = " << root << "): ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 对堆进行排序
    std::sort_heap(vec.begin(), vec.end());
    std::cout << "After sort_heap: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
