#include <iostream>
#include <cstdlib>  // malloc 和 free

int main() {
    
    // malloc内存分配失败时会返回NULL，需要手动检查

    // 使用 malloc 分配内存
    int* arr = (int*)malloc(5 * sizeof(int));  // 分配 5 个 int 的内存
    if (arr == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }

    // 使用内存
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
        std::cout << arr[i] << " ";  // 输出分配的内存中的值
    }
    std::cout << std::endl;

    /* free是如何知道内存块大小？
    free函数不需要知道你在malloc时指定的内存大小。实际上，free不依赖于你显式告诉它内存大小
    这是因为在分配内存时，内存分配器会在系统层面管理内存块的大小信息。
    
    
    
    */


    // 释放内存
    free(arr);  // 使用 free 释放内存


    return 0;
}
