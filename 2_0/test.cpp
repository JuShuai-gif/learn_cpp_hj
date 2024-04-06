#include<iostream>
#include "CustomerHash.h"

int main(){
    std::cout << __cplusplus << std::endl;

    CustomerHash customer{"John", "Doe", 12345}; // 创建一个CustomerHash对象
    std::size_t hashValue = customer(customer); // 调用哈希函数
    std::cout << "hashValue: " << hashValue << std::endl;
    return 0;
}