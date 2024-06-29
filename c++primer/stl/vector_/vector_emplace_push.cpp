#include <vector>
#include <iostream>
#include <chrono>

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

int main() {
    /****** emplace_back: 将一个就地构造的元素添加到向量末尾 *******/
    /*
    template <class... Types>
    void emplace_back(Types&&... args);
    参数：
    构造函数参数。函数根据所提供的自变量来推断要调用的构造函数重载
    */
    std::vector<Person> v23;
    std::vector<Person> v24;
    int num = 100;
    for (size_t j = 0; j < 5; j++) {
        // 获取开始时间点
        auto start = std::chrono::high_resolution_clock::now();
        // emplace_back支持
        for (size_t i = 0; i < num; i++) {
            v23.emplace_back(26, "ghr");
        }
        // 获取结束时间点
        auto end = std::chrono::high_resolution_clock::now();

        // 计算运行时间
        std::chrono::duration<double> duration = end - start;

        // 输出运行时间
        std::cout << "Iterator " << num << " emplace_back time: " << duration.count() << " seconds" << std::endl;

        // 获取开始时间点
        auto start1 = std::chrono::high_resolution_clock::now();
        // emplace_back支持
        for (size_t i = 0; i < num; i++) {
            v24.push_back(Person(26, "ghr"));
        }
        // 获取结束时间点
        auto end1 = std::chrono::high_resolution_clock::now();

        // 计算运行时间
        std::chrono::duration<double> duration1 = end1 - start1;

        // 输出运行时间
        std::cout << "Iterator " << num << " push_back time: " << duration1.count() << " seconds" << std::endl;

        num*=100;
    }

    return 0;
}
