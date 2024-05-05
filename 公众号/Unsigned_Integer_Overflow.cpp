/* 使用更大的整数类型进行比较

#include <iostream>
#include <limits>

int main() {
    unsigned int a = 4294967290; // 假设是32位无符号整数，接近最大值
    unsigned int b = 10;
    
    // 使用更大的整数类型进行计算
    unsigned long long sum_ull = static_cast<unsigned long long>(a) + b;
    
    // 检查是否溢出
    if (sum_ull > std::numeric_limits<unsigned int>::max()) {
        std::cout << "Overflow detected!" << std::endl;
    } else {
        unsigned int sum = static_cast<unsigned int>(sum_ull);
        std::cout << "The sum is: " << sum << std::endl;
    }

    std::cout << "int max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "int8_t max: " << std::numeric_limits<int8_t>::max() << std::endl;
    std::cout << "int16_t max: " << std::numeric_limits<int16_t>::max() << std::endl;
    std::cout << "int32_t max: " << std::numeric_limits<int32_t>::max() << std::endl;
    std::cout << "int64_t max: " << std::numeric_limits<int64_t>::max() << std::endl;
    std::cout << "float max: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "double max: " << std::numeric_limits<double>::max() << std::endl;
    
    return 0;
}
*/

#include <iostream>
#include <limits>

bool checkAdditionOverflow(unsigned int a, unsigned int b) {
    if (b > std::numeric_limits<unsigned int>::max() - a) {
        return true; // 溢出
    }
    return false; // 未溢出
}

int main() {
    std::cout << std::numeric_limits<unsigned int>::max() << std::endl;
    unsigned int a = 4294967290; // 假设是32位无符号整数，接近最大值
    unsigned int b = 10;
    
    if (checkAdditionOverflow(a, b)) {
        std::cout << "Overflow detected!" << std::endl;
    } else {
        unsigned int sum = a + b;
        std::cout << "The sum is: " << sum << std::endl;
    }
    
    return 0;
}


