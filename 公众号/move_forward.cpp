/*   move 移动语义
#include <iostream>
#include <memory>

class OBject
{ 
public:
    OBject(){
        std::cout << "构造函数！！！" << std::endl;
    }
    ~OBject(){
        std::cout << "析构函数！！！" << std::endl;
    }

    void fun(){
        std::cout << "in fun " << std::endl;
    }

};

int main(){
    std::unique_ptr<OBject> p1 = std::make_unique<OBject>();

    std::unique_ptr<OBject> p2 = std::move(p1);
    if (p1){
        std::cout << "p1 is not empty" << std::endl;
    }
    p2->fun();
    

    return 0;
}
*/

/* forward 完美转发

#include <iostream>

void Print(const int& lref) {
    std::cout << "Lvalue reference" << std::endl;
}

void Print(int&& rref) {
    std::cout << "Rvalue reference" << std::endl;
}

template<typename T>
void Fun(T&& param) {
    Print(std::forward<T>(param));
}

int main() {
    int x = 5;
    const int y = 10;

    Fun(x);   // lvalue reference
    Fun(y);   // lvalue reference
    Fun(20);  // rvalue reference

    return 0;
}
*/

/* move 和 forward的区别

*/
#include <iostream>

void Print(int& a){
    std::cout << "int&: " << a << std::endl;
}

void Print(int&& a){
    std::cout << "int&&: " << a << std::endl;
}

template <typename T>
void func1(T&& a){
    Print(std::move(a));
}

template <typename T>
void func2(T&& a){
    Print(std::forward<T>(a));
}

int main() {
    int arg = 10;

    std::cout << "Calling func1 with std::move()..." << std::endl;
    func1(arg); /* arg is an lvalue */
    func1(25);  /* 25 is an rvalue  */

    std::cout << "Calling func2 with std::forward()..." << std::endl;
    func2(arg); /* arg is an lvalue */
    func2(25);  /* 25 is an rvalue  */

    return 0;
}





