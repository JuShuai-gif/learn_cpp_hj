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
        persons.emplace_back(30, "Person " + std::to_string(i));
    }
    return 0;
}


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
}*/

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

