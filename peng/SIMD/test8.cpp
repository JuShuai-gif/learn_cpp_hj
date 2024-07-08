#include <iostream>
#include <emmintrin.h> // 包含SSE2指令集

int main() {
    // 创建并初始化两个__m128i变量
    __m128i a = _mm_set_epi32(4, 3, 2, 1); // 初始化为[4, 3, 2, 1]
    __m128i b = _mm_set_epi32(8, 7, 6, 5); // 初始化为[8, 7, 6, 5]

    // 执行并行加法运算
    __m128i c = _mm_add_epi32(a, b); // c = [12, 10, 8, 6]

    // 提取并打印结果
    int* result = (int*)&c;
    std::cout << "Results: " << result[0] << ", " << result[1] << ", " << result[2] << ", " << result[3] << std::endl;

    return 0;
}
