#include <iostream>
#include <vector>

int main() {
    // 4个元素，每个元素的值为2
    std::vector<std::int16_t> v{1,2,3,4};
    // 4个元素，每个元素都是对应的地址
    std::vector<std::int16_t *> index;

    // 打印向量中每个元素的地址
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "Address of v[" << i << "] = " << &v[i] << std::endl;
        index.push_back(&v[i]);
    }

    for (auto i:index)
    {
        std::cout << "Address " << i << std::endl;
    }

    /* 输出结果 从侧面可以看出 int16_t占2个字节
    Address 0x56482267deb0
    Address 0x56482267deb2
    Address 0x56482267deb4
    Address 0x56482267deb6
    */

    // 4个元素，每个元素的值为2
    std::vector<std::int32_t> v1{1,2,3,4};
    // 4个元素，每个元素都是对应的地址
    std::vector<std::int32_t *> index1;

    // 打印向量中每个元素的地址
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << "Address of v[" << i << "] = " << &v1[i] << std::endl;
        index1.push_back(&v1[i]);
    }

    for (auto i:index1)
    {
        std::cout << "Address " << i << std::endl;
    }

    /* 输出结果 从侧面可以看出 int32_t 占4个字节
    Address 0x55ff4aabb300
    Address 0x55ff4aabb304
    Address 0x55ff4aabb308
    Address 0x55ff4aabb30c
    */
    std::vector<std::int32_t>::iterator iter1,iter2;
    iter1 = v1.begin();
    iter2 = v1.end();

    std::cout << "iter1: " << &(*iter1) << std::endl;
    std::cout << "iter2: " << &(*iter2) << std::endl;

    std::cout << "*iter2: " << *(iter2-1) << std::endl;

    return 0;
}
