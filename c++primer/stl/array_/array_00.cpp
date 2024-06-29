#include <array>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::array<int, 4> Myarray;

std::vector<int> vec;
/*
这里注意，array和vector的模版参数是不一样的，array两个参数分别是 类型和大小
vector两个参数是 类型和分配器 当然可以使用第一个类型即可，第二个可以采用默认的
*/

int main() {
    /***** 1. array：array构造函数 ****/
    /*
    array();
    array(const array& right);
    */

    // 1. 使用初始化列表
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};

    // 2. 默认初始化，未定义行为(应该避免)
    std::array<int, 5> arr2{12};

    // 3. 使用 fill 方法
    std::array<int, 5> arr3;
    arr3.fill(10); // 所有元素初始化为 10

    // 4. 使用赋值操作符
    std::array<int, 5> arr4 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr5;
    arr5 = arr4; // arr5 现在与 arr4 相同

    // 打印数组元素
    for (int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    Myarray c0 = {0, 1, 2, 3};
    for (const auto &it : c0) {
        std::cout << " " << it;
    }
    std::cout << std::endl;
    Myarray c1(c0);
    for (const auto &it : c1) {
        std::cout << " " << it;
    }
    std::cout << std::endl;

    /***** 2. fill: ******/
    /*
    void fill(const Type& val);
    参数：
    val: 要插入到数组中的元素的值
    注解：fill将数组的每个元素替换为指定的值
    C++11中array::assign已经过时的，被fill替代，替换所有元素
    */
    array<int, 2> v1 = {1, 2};

    cout << "v1 = ";
    for (const auto &it : v1) {
        std::cout << " " << it;
    }
    cout << endl;

    v1.fill(3);
    cout << "v1 = ";
    for (const auto &it : v1) {
        std::cout << " " << it;
    }
    cout << endl;

    /**** 3. at: 访问指定位置处的元素 ****/
    // cout << v1[30] << endl;
    // 访问位置超出 vector 的边界，行为是未定义的(underfined behavior)，
    // 这意味着行为会崩溃、输出垃圾值、或者看着在运行实际逻辑已经错误了
    // cout << v1.at(30) << endl;
    // at 方法会进行边界检查。
    // 如果访问的位置超出 vector 的边界，它会抛出一个 std::out_of_range 异常。
    // 这是更安全的访问方式，特别是在不确定索引是否有效的情况下。

    // 其实array和vector的函数大多数都是类似的，不用一一讲解，其实只关注差异即可
    /*
    array 容器的大小是固定的，无法动态的扩展或收缩，
    这也就意味着，在使用该容器的过程无法借由增加或移除元素而改变其大小，它只允许访问或者替换存储的元素。
    它的内存分布连续
    */

    array<float, 10> x;
    for (auto i : x) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> vx(10); //
    for (auto i : vx) {
        cout << i << " ";
    }
    cout << endl;

    int i;
    cout << i << endl;

    array<int, 5> v2{1, 2, 3, 4, 5};
    array<int, 5> v3{7, 8, 9, 10, 11};
    cout << v2.data() << endl;
    cout << v3.data() << endl;
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v3) {
        cout << i << " ";
    }
    cout << endl;
    // 只能交换大小相同array
    swap(v2, v3);
    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v3) {
        cout << i << " ";
    }
    cout << endl;
    cout << v2.data() << endl;
    cout << v3.data() << endl;

    array<int, 5> v4{1, 2, 3, 4, 5};
    array<int, 5> v5{7, 8, 9, 10, 11};
    cout << v4.data() << endl;
    cout << v5.data() << endl;
    v4.swap(v5);
    cout << v4.data() << endl;
    cout << v5.data() << endl;

    // 初始化为0
    // array<int, 5> v4{};
    // for (auto i : v4) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // 未定义行为
    // array<int, 5> v5;
    // for (auto i : v5) {
    //     cout << i << " ";
    // }
    // cout << endl;

    return (0);
}