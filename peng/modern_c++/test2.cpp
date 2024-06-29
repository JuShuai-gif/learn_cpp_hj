#include <iostream>
#include <string>

using namespace std;

template <class T>
string get_type_name() {
    string s = __PRETTY_FUNCTION__;
    auto pos = s.find("T = ");
    pos += 4;
    auto pos2 = s.find_first_of(";]", pos);
    /*
    find_first_of：查找多个可能字符的首次出现。第一个参数是一个字符串集合
    find_first_not_of：查找第一个不在指定字符集合中的字符。
    find_last_of：查找多个可能字符的最后一次出现。
    find_last_not_of：查找最后一个不在指定字符集合中的字符。
    find：查找特定子字符串或字符的首次出现。
    s.find_first_not_of();
    s.find_last_of();
    s.find_last_not_of();
    s.find();
    */
    return s.substr(pos, pos2 - pos);
}

namespace myUtils {
class Car {
};
} // namespace myUtils

template <class T, T N>
string get_int_name() {
    string s = __PRETTY_FUNCTION__;
    auto pos = s.find("N = ");
    pos += 4;
    auto pos2 = s.find_first_of(";]", pos);
    return s.substr(pos, pos2 - pos);
}

enum Color {
    RED = 1,
    GREEN = 2,
    BLUE = 3,
};

// 如果想要使用运行时变量传参怎么办
template <class T>
string get_int_name_dynamic(T n) {
    if (n == T(1))
        return get_int_name<T, (T)1>();
    if (n == T(2))
        return get_int_name<T, (T)2>();
    if (n == T(3))
        return get_int_name<T, (T)3>();
}

int main() {
    // Color c = RED;
    // 这样写是会报错的，因为Color c = RED; 是运行时的变量，而模版参数是编译时变量
    // cout << get_int_name<Color,c>() << endl;

    constexpr Color c = RED;
    // 这样写是会报错的，因为Color c = RED; 是运行时的变量，而模版参数是编译时变量
    cout << get_int_name<Color, c>() << endl;

    // 运行时
    Color cc = GREEN;
    cout << get_int_name_dynamic(cc) << endl;

    cout << get_type_name<myUtils::Car>() << endl;
    cout << get_int_name<char, 1>() << endl;
    cout << get_int_name<Color, (Color)3>() << endl;
}
