#include <iostream>
#include <vector>
#include <algorithm>

// 投射函数：返回 pair 的第一个元素
template <class Arg1, class Arg2>
struct projectfirst {
    Arg1 operator()(const std::pair<Arg1, Arg2>& p) const {
        return p.first;
    }
};

// 投射函数：返回 pair 的第二个元素
template <class Arg1, class Arg2>
struct projectsecond {
    Arg2 operator()(const std::pair<Arg1, Arg2>& p) const {
        return p.second;
    }
};

int main() {
    std::vector<std::pair<int, std::string>> vec = {
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    std::vector<int> keys(vec.size());
    std::vector<std::string> values(vec.size());

    // std::transform 用于将一个范围内的每个元素应用一个给定的操作，并将结果存储在另一个范围内
    // 使用 projectfirst 提取第一个元素
    std::transform(vec.begin(), vec.end(), keys.begin(),
                   projectfirst<int, std::string>());

    // 使用 projectsecond 提取第二个元素
    std::transform(vec.begin(), vec.end(), values.begin(),
                   projectsecond<int, std::string>());

    std::cout << "Keys: ";
    for (const auto &key : keys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::cout << "Values: ";
    for (const auto &value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
