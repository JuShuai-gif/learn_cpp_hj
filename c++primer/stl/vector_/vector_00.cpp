
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Person {
public:
    Person(int age, std::string name) :
        age_(age), name_(name) {
    }
    Person() = delete;

private:
    int age_;
    std::string name_;
    friend std::ostream &operator<<(std::ostream &os, Person &person);
};
std::ostream &operator<<(std::ostream &os, Person &person) {
    os << "age: " << person.age_ << " name: " << person.name_ << "\n";
    return os;
}

template <typename C>
void print(const string &s, const C &c) {
    cout << s;

    for (const auto &e : c) {
        cout << e << " ";
    }
    cout << endl;
}

void printvstats(const vector<int> &v) {
    cout << "   the vector's size is: " << v.size() << endl;
    cout << "   the vector's capacity is: " << v.capacity() << endl;
    cout << "   the vector's maximum size is: " << v.max_size() << endl;
}

int main() {
    /* 1. vector: 构造向量。 重载构造一个特定大小的向量，或具有特定值的元素的向量。
     或者，作为其他某个向量的整体或一部分的副本。 某些重载还允许指定要使用的分配器

    vector();
    explicit vector(const Allocator& allocator);
    explicit vector(size_type count);
    vector(size_type count, const Type& value);
    vector(size_type count, const Type& value, const Allocator& allocator);

    vector(const vector& source);
    vector(vector&& source);
    vector(initializer_list<Type> init_list, const Allocator& allocator);

    template <class InputIterator>
    vector(InputIterator first, InputIterator last);
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const Allocator& allocator);

    参数：
    allocator 要用于此对象的分配器类。 get_allocator 返回对象的分配器类。

    count 构造的矢量中的元素数。

    value 构造的矢量中的元素值。

    source 要成为副本的构造的矢量中的矢量。

    first 要复制的元素范围内的第一个元素的位置。

    last 要复制的元素范围外的第一个元素的位置。

    init_list 包含要复制的元素的 initializer_list。

     */
    // 创建一个空 vector 
    vector<int> v011;

    // 创建一个包含三个元素的vector 默认元素为0
    vector<int> v111(3);
    for (auto &&i : v111)
    {
        cout << i << " ";
    }
    cout << endl;
    

    // 创建一个包含五个元素的vector 默认值都是2
    vector<int> v211(5, 2);

    // Create a vector v3 with 3 elements of value 1 and with the allocator
    // of vector v2
    vector<int> v311(3, 1, v211.get_allocator());

    // Create a copy, vector v4, of vector v2
    vector<int> v411(v211);

    // Create a new temporary vector for demonstrating copying ranges
    vector<int> v511(5);
    for (auto i : v511) {
        v511[i] = i;
    }

    // Create a vector v6 by copying the range v5[ first,  last)
    vector<int> v611(v511.begin() + 1, v511.begin() + 3);

    /*********** 2. assign:清楚矢量并将指定的元素赋值到该空 vetor 中 ************/
    /*
    void assign(size_type count, const Type& value);
    void assign(initializer_list<Type> init_list);
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last);
    */
    std::vector<int> v1, v2, v3;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    std::cout << "v1 = ";
    for (auto &v : v1) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    // 使用迭代器 指定返回的元素
    v2.assign(v1.begin(), v1.end());
    std::cout << "v2 = ";
    for (auto &v : v2) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    // 参数：数量 值
    v3.assign(7, 4);
    std::cout << "v3 = ";
    for (auto &v : v3) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    // 将初始化列表中的数据指定到这个 vector 中
    v3.assign({5, 6, 7});
    for (auto &v : v3) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    /************* 3. at 返回对矢量中指定位置的元素的引用(会进行安全检查) ***************/
    /*
    参数：position 矢量中引用元素的下表或位置编号
    返回值：对自变量中的下标元素的引用。如果position 大于向量的大小，则at会引发异常
    注：如果将 at 的返回值分配给 const_reference ，则可以修改向量对象。 如果将 at 的返回
        值分配给 reference ，则可以修改矢量对象。
    */
    vector<int> v11;
    v11.push_back(10);
    v11.push_back(20);
    const int &i = v11.at(0);
    int &j = v11.at(1);
    cout << "The first element is " << i << endl;
    v11[0] = 11;
    cout << "改变之后的at数据 " << i << endl;
    cout << "The second element is " << j << endl;
    j = 22;
    cout << "改变之后的 vector 元素: " << v11[1] << endl;

    std::vector<Person> persons;

    std::cout << "max_size: " << persons.max_size() << std::endl;

    /************** 4. back: 返回对 vector 中最后一个元素的引用 **************/
    /*
    返回值：向量最后一个元素，如果向量为空，返回值不确定
    注解：如果将 back 的返回值分配给 const_reference ，则可以修改向量对象。 如果将 back 的
        返回值分配给 reference ，则可以修改矢量对象。
    */
    // 切记：不能访问空的 vector
    vector<int> v12;
    v12.push_back(10);
    v12.push_back(11);
    int &i12 = v12.back();
    const int &ii12 = v12.front();
    cout << "The last integer of v1 is " << i12 << endl;
    i12--;
    cout << "The next-to-last integer of v1 is " << ii12 << endl;

    /************** 5. begin: 对该 vector 中第一个元素返回随机访问迭代器 **************/
    /************** 6. cbegin: 返回确定范围中第一个元素地址的 const 迭代器 **************/
    /************** 7. cend: 返回 const 超过末尾迭代器，该迭代器指向向量最后一个元素之后的元素 **************/
    /*
    返回值：发现 vector 中第一个元素或空 vector 之后的位置的随机访问迭代器。 始终将返回的值
            与 vector::end 进行比较以确保其有效
    注解：如果将 begin 的返回值分配给 vector::const_iterator，则可以修改 vector 对象。 如果将
            begin 的返回值分配给 vector::iterator，则可以修改 vector 对象
    */

    vector<int> c1;
    // 定义 vector<int> 的迭代器
    vector<int>::iterator c1_Iter; // 允许通过解引用修改元素的值
    // 可以将 iterator 转换为 const_iterator，但不能将 const_iterator 转换为 iterator
    vector<int>::const_iterator c1_cIter; // 通过解引用只能读取元素的值，不能修改
    // 注意：现代C++格式应尽量使用 auto 定义
    c1.push_back(1);
    c1.push_back(2);
    cout << "The vector c1 contains elements:";
    c1_Iter = c1.begin();
    for (; c1_Iter != c1.end(); c1_Iter++) {
        cout << " " << *c1_Iter;
    }
    cout << endl;
    cout << "The vector c1 now contains elements:";
    auto c1_Iter2 = c1.begin();
    *c1_Iter2 = 20;
    for (; c1_Iter2 != c1.end(); c1_Iter2++) {
        cout << " " << *c1_Iter2;
    }
    cout << endl;

    /********* 8. capacity: 返回在不分配更多的存储的情况下向量可以包含的元素数 *********/
    /*
    返回值：分配给该向量的当前存储长度
    注解：如果为成员函数 resize 分配了足够的内存，它将更高效。 使用成员函数 reserve 指定分
            配的内存量
    */
    // 从这里可以看出，vector是2倍增长的，并且在扩容之后，它会将数据移到另一块空间中
    // resize会改变大小size，如果少于原来的，则缩减元素，如果大于则补0
    // reserve 会改变capacity的大小，而不会改变size的

    vector<int> v13;
    v13.push_back(1);
    cout << "一个元素的长度 "
         << v13.capacity() << "." << endl;
    v13.push_back(2);
    v13.push_back(3);
    cout << "三个元素的长度 "
         << v13.capacity() << "." << endl;
    v13.resize(2);
    for (auto &&i : v13) {
        cout << i << " ";
    }
    cout << endl;
    cout << "resize(2)之后的size大小: " << v13.size() << endl;
    cout << "resize(2)之后的capacity大小: " << v13.capacity() << endl;

    v13.resize(4);
    cout << "resize(4)之后的v13元素: " << endl;
    for (auto &&i : v13) {
        cout << i << " ";
    }
    cout << endl;
    v13.push_back(12);
    v13.push_back(15);
    cout << "push_back 12 15之后的v13元素: " << endl;
    for (auto &&i : v13) {
        cout << i << " ";
    }
    cout << endl;

    cout << "resize(4)之后的size大小: " << v13.size() << endl;
    cout << "resize(4)之后的capacity大小: " << v13.capacity() << endl;

    v13.reserve(32);
    cout << "resize(4)之后的size大小: " << v13.size() << endl;
    cout << "resize(4)之后的capacity大小: " << v13.capacity() << endl;

    v13.resize(2);
    cout << "resize(4)之后的size大小: " << v13.size() << endl;
    cout << "resize(4)之后的capacity大小: " << v13.capacity() << endl;

    /*********** 9. clear: 清除向量的元素 ***********/
    vector<int> v14;
    v14.push_back(10);
    v14.push_back(20);
    v14.push_back(30);
    cout << "The size of v1 is " << v14.size() << endl;
    v14.clear();
    cout << "The size of v1 after clearing is " << v14.size() << endl;

    /****** 10. const_iterator: 一个类型，它提供可读取矢量中 const 元素的随机访问迭代器 ******/
    /****** 11. const_pointer: 一个类型，它提供指向矢量中 const 元素的指针 ******/

    /****** 12. const_reference: 一个类型，它提供对向量中存储的 const 元素的引用。 它用于读取和执行 const 操作 ******/

    vector<int> v15;

    v15.push_back(10);
    v15.push_back(20);

    const vector<int> v25 = v15;
    const int &i15 = v25.front();
    const int &j15 = v25.back();
    cout << "The first element is " << i15 << endl;
    cout << "The second element is " << j15 << endl;

    // 常量数组是不可以更改它的内容的
    // v25.push_back( 30 );

    /****** 13. const_reverse_iterator: 一个类型，它提供可读取矢量中任何 const 元素的随机访问迭代器 ******/
    /****** 14. rbegin: 返回指向反向向量中第一个元素的迭代器 ******/
    /****** 15. rend: 返回指向反向向量中最后一个元素的上一个元素的迭代器 ******/
    /****** 16. reverse_iterator: 一个类型，它提供可读取或修改反向矢量中的任意元素的随机访问迭代器 ******/

    vector<int> v16;
    vector<int>::iterator v16_Iter;
    vector<int>::reverse_iterator v16_rIter;

    v16.push_back(1);
    v16.push_back(2);

    v16_Iter = v16.begin();
    cout << "The first element of vector is "
         << *v16_Iter << "." << endl;

    v16_rIter = v16.rbegin();
    cout << "The first element of the reversed vector is "
         << *v16_rIter << "." << endl;

    v16.push_back(3);
    v16.push_back(4);
    // 反向输出
    // 使用rbegin和rend必须使用反向迭代器reverse_iterator
    for (v16_rIter = v16.rbegin(); v16_rIter != v16.rend(); v16_rIter++)
        cout << *v16_rIter << endl;

    /********** shrink_to_fit：放弃额外容量 **********/
    vector<int> v17;
    // vector <int>::iterator Iter;
    // 填充一个元素
    v17.push_back(1);
    cout << "Current capacity of v1 = "
         << v17.capacity() << endl;
    // 申请 20 个空间
    v17.reserve(20);
    cout << "Current capacity of v1 = "
         << v17.capacity() << endl;
    // 去除没用的空间
    v17.shrink_to_fit();
    cout << "Current capacity of v1 = "
         << v17.capacity() << endl;

    /************ 17. swap: 交换两个向量的元素 *************/
    /*
    void swap(
    vector<Type, Allocator>& right);

    friend void swap(
    vector<Type, Allocator>& left,
    vector<Type, Allocator>& right);
    参数：
    right: 一个提供要交换的元素的向量。 或者一个其元素将与向量 left 中的元素进行交换的向量
    left: 一个其元素将与向量 right 中的元素进行交换的向量
    */

    /*   swap学习笔记
    1. 它的时间复杂度是 O(1)
    因为标准库中，std::vector其实就是维护了几个指针和数据成员（一个指向数据开头的指针、一个指向数据块末尾的指针、一个指向数据块容量末尾的指针）
    swap 函数通过交换这些指针和数据成员来实现两个 vector 的内容交换，而不涉及实际的数据拷贝

    */

    vector<int> v18, v28;

    v18.push_back(1);
    v18.push_back(2);
    v18.push_back(3);

    v28.push_back(10);
    v28.push_back(20);

    cout << "The number of elements in v1 = " << v18.size() << endl;
    cout << "The number of elements in v2 = " << v28.size() << endl;
    cout << endl;

    v18.swap(v28);

    cout << "The number of elements in v1 = " << v18.size() << endl;
    cout << "The number of elements in v2 = " << v28.size() << endl;

    /************* 18. value_type：一个类型，它代表向量中存储的数据类型 ***************/
    vector<int>::value_type AnInt;
    AnInt = 44;
    cout << AnInt << endl;
}

/*
#include <vector>
#include <string>

class Person {
public:
    Person(int age, std::string name) : age_(age), name_(name) {}
    Person() = delete;
private:
    int age_;
    std::string name_;
};

int main() {
    std::vector<Person> persons;
    persons.reserve(10);  // 预留空间
    for (int i = 0; i < 10; ++i) {
        persons.emplace(persons.end(), 30, "Person " + std::to_string(i));
    }
    return 0;
}

#include <vector>
#include <string>
#include <algorithm>

class Person {
public:
    Person(int age, std::string name) : age_(age), name_(name) {}
    Person() = delete;
private:
    int age_;
    std::string name_;
};

int main() {
    std::vector<Person> persons;
    persons.reserve(10);  // 预留空间
    std::generate_n(std::back_inserter(persons), 10, [n = 0]() mutable {
        return Person(30, "Person " + std::to_string(n++));
    });
    return 0;
}
*/
