#include <iostream>
#include <algorithm>
#include <vector>

/* std::minmax_element 函数讲解
该函数在一次遍历中完成最小值和最大值的查找，
因此比分别调用 std::min_element 和 std::max_element 更高效

first, last: 表示输入范围的起始和结束迭代器。
comp: 一个可选的二元比较函数对象（或谓词），用于定义比较规则。
如果没有提供，默认使用 operator <

** 细节和注意事项
1. std::minmax_element 只对前向迭代器（ForwardIt）有效。
它可以用于支持至少前向迭代器的容器（如 std::vector, std::list, std::deque）。

2. 当范围为空时，返回的一对迭代器都等于 last。
自定义比较函数 comp 应满足严格弱序的要求。

3. 由于 std::minmax_element 在一次遍历中完成查找，
理论上它比分别调用 std::min_element 和 std::max_element 能减少比较次数。

*/


/********* 默认排序函数 *********/
void DefaultSort(std::vector<int> &vec) {
    auto result = std::minmax_element(vec.begin(), vec.end());

    if (result.first != vec.end()) {
        std::cout << "Min element: " << *result.first << std::endl;
        std::cout << "Max element: " << *result.second << std::endl;
    } else {
        std::cout << "The range is empty." << std::endl;
    }
}

/******* 自定义比较函数 ******/
struct Point {
    int x;
    int y;
};

bool compare_by_x(const Point &a, const Point &b) {
    return a.x < b.x;
}

void CustomSort(std::vector<Point> &points) {
    auto result = std::minmax_element(points.begin(), points.end(), compare_by_x);

    if (result.first != points.end()) {
        std::cout << "Min element by x: (" << result.first->x << ", " << result.first->y << ")" << std::endl;
        std::cout << "Max element by x: (" << result.second->x << ", " << result.second->y << ")" << std::endl;
    } else {
        std::cout << "The range is empty." << std::endl;
    }
}

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::vector<Point> points = {{3, 1}, {1, 2}, {4, 1}, {1, 5}, {5, 0}};

    DefaultSort(vec);
    CustomSort(points);


    return 0;
}
