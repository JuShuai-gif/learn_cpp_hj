/**
 * @file accumlate_test.cpp
 * @author GHR (208967048@qq.com)
 * @brief 测试 accumlate
 * @version 0.1
 * @date 2024-06-15
 */
#include <vector>
// accumlate 位于numeric头文件中
#include <numeric>

#include <iostream>

// 定义自定义类型Point
struct Point {
    int x, y;

    // 默认构造函数
    Point() :
        x(0), y(0) {
    }

    // 构造函数
    Point(int x, int y) :
        x(x), y(y) {
    }

    // 重载加法运算符
    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y);
    }
};

// 重载 << 便于打印
std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// 使用自定义二元操作
struct Car
{
    public:
    std::string name_;
    int id_;

    Car(const std::string name=" ",const int id=0):name_(name),id_(id){

    }

    int operator+(const Car& other)const{
        return int(id_ + other.id_);
    }
};


int main() {
    std::vector<int> v_i{1, 2, 3, 4, 5, 6};

    std::vector<double> v_d{1.5, 2.6, 3.456, 4.123, 5.258, 6.159357};

    std::vector<Point> points = {{1, 2}, {3, 4}, {5, 6}};

    std::vector<Car> cars = {{"a", 21}, {"b", 15}, {"c", 6}};

    // 使用std::accumulate计算总和
    Point sum = std::accumulate(points.begin(), points.end(), Point());

    int sum_i = std::accumulate(v_i.begin(), v_i.end(), 0);

    double sum_d = std::accumulate(v_d.begin(), v_d.end(), 0.0);

    // 使用std::accumulate计算id_的总和
    int total_id_sum = std::accumulate(cars.begin(), cars.end(), 0,
                                       [](int sum, const Car &car) {
                                           return sum + car.id_;
                                       });

    std::cout << "sum_i: " << sum_i << std::endl;

    std::cout << "sum_d: " << sum_d << std::endl;

    std::cout << "Sum of points: " << sum << std::endl;

    std::cout << "Total id sum: " << total_id_sum << std::endl;

    return 0;
}