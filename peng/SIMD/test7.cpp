// 使用SIMD指令优化的向量加法
#include <emmintrin.h> // 包含SSE2指令集

__m128i vector_add(__m128i a, __m128i b) {
    return _mm_add_epi32(a, b);
}


#include <x86intrin.h>

void add_vectors(int* a, int* b, int* c, int size) {
    for (int i = 0; i < size; i += 4) {
        __m128i va = _mm_load_si128((__m128i*)(a + i));
        __m128i vb = _mm_load_si128((__m128i*)(b + i));
        __m128i vc = _mm_add_epi32(va, vb);
        _mm_store_si128((__m128i*)(c + i), vc);
    }
}
