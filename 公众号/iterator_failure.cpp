/*
#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec{5};
    
    auto it = vec.begin();
    std::cout << "vec.capacity: " << vec.capacity() << std::endl;
    std::cout << "it: " << *it << std::endl;
    std::cout << "it address: " << &*it  << std::endl;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    std::cout << "vec.capacity: " << vec.capacity() << std::endl;
    std::cout << "it: " << *it << std::endl;
    std::cout << "it address: " << &*it  << std::endl;
    std::cout << "it address: " << &*(vec.begin())  << std::endl;
    return 0;
}
*/

#include <iostream>
#include <string>


struct X
{
    int num{42};
    ~X() { std::cout << "X destroyed" << '\n';}
    
};

class MyClass
{
public:
    explicit MyClass(X const& x) : x_(x) {}
    void print() const
    {
        std::cout << "num: " << x_.num << std::endl;
    }
private:
    X const& x_;
};

int main(){
    X x;
    MyClass myObject{x};
    myObject.print();

    MyClass myObject1{X{}};
    std::cout << "before print" << '\n';
    myObject1.print();
    return 0;
}



