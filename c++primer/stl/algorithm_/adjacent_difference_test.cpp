#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include <iostream>

struct Point {
public:
    int x_{};
    int y_{};
    Point() :
        x_(0), y_(0) {
    }

    Point(int x, int y) :
        x_(x), y_(y) {
    }

    Point operator+(const Point &p) {
        return {x_ + p.x_, y_ + p.y_};
    }
};

// 格式化输出
std::ostream& operator<< (std::ostream& os,const Point& p){
    os << "(" << p.x_ << "," << p.y_ << ")\n";
    return os;
}

int main() {
    using namespace std;

    vector<int> V1(10), V2(10);
    vector<int>::iterator VIter1, VIter2, VIterend, VIterend2, VIterend3;

    std::vector<Point> points1{{1,2},{2,3},{3,4},{4,5},{5,6}};
    std::vector<Point> points2(5);
    std::vector<Point>::iterator pointIter1,pointIter2;

    list<int> L1;
    list<int>::iterator LIter1, LIterend, LIterend2;

    int t;
    for (t = 1; t <= 10; t++) {
        L1.push_back(t * t);
    }

    cout << "使用迭代器输出 L1 :\n ( ";
    for (LIter1 = L1.begin(); LIter1 != L1.end(); LIter1++)
        cout << *LIter1 << " ";
    cout << ")." << endl;

    // 将L1作为输入，V1作为输出，adjacent_difference得到的是迭代器类型
    VIterend = adjacent_difference(L1.begin(), L1.end(),
                                   V1.begin());

    cout << "相邻元素相减:\n ( ";
    for (VIter1 = V1.begin(); VIter1 != VIterend; VIter1++)
        cout << *VIter1 << " ";
    cout << ")." << endl;

    // The second member function used to compute
    // the adjacent products of the elements in a list
    VIterend2 = adjacent_difference(L1.begin(), L1.end(), V2.begin(),
                                    multiplies<int>());

    cout << "相邻元素相乘:\n ( ";
    for (VIter2 = V2.begin(); VIter2 != VIterend2; VIter2++)
        cout << *VIter2 << " ";
    cout << ")." << endl;

    // 返回值 VIterend3 是关于 V2 的迭代器
    VIterend3 = adjacent_difference(L1.begin(), L1.end(), V2.begin(),
                                    [](int &a, int &b) {
                                        return a + b;
                                    });

    cout << "相邻元素相加:\n ( ";
    for (VIter2 = V2.begin(); VIter2 != VIterend3; VIter2++)
        cout << *VIter2 << " ";
    cout << ")." << endl;

    // 自定义二元操作
    pointIter1 = adjacent_difference(points1.begin(), points1.end(), points2.begin(),
                                    [](Point &a, Point &b) {
                                        return Point(a.x_,a.y_ + b.y_);
                                    });
    for (pointIter2 = points2.begin(); pointIter2 != pointIter1; pointIter2++)
        std::cout << *pointIter2 << " ";
    cout << endl;

    // Computation of adjacent_differences in place
    LIterend2 = adjacent_difference(L1.begin(), L1.end(), L1.begin());
    cout << "In place output adjacent_differences in list L1 is:\n ( ";
    for (LIter1 = L1.begin(); LIter1 != LIterend2; LIter1++)
        cout << *LIter1 << " ";
    cout << ")." << endl;
}