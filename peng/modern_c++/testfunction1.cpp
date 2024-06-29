#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

template < typename Ret, typename... Args >
struct Function;

template < typename Ret, typename... Args >
struct Function< Ret(Args...) > {
    struct Base {
        virtual Base* clone() = 0;
        virtual Ret operator()(Args &&... args) = 0;
    };


    template<typename T>
    struct Data : Base {
        T func;
        Data(const T& t) : func(t) {}
        virtual Base* clone() { return new Data<T>(func); }
        virtual Ret operator()(Args &&... args) {
            return func(std::forward< Args >(args)...);
        }
    };
    Base* ptr;
    Function() : ptr{ nullptr } {}
    template<typename T>
    Function(T t) : ptr{ new Data<T>(t) } {};
    Function(const Function& rhs) {
        ptr = rhs.ptr->clone();
    }
    Function& operator=(const Function& rhs) {
        if (ptr)delete ptr;
        ptr = rhs.ptr->clone();
        return *this;
    }
    Function(Function&& rhs) noexcept {
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
    }
    Function& operator=(Function&& rhs) noexcept {
        if (ptr)delete ptr;
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
        return *this;
    }
    Ret operator()(Args... args) {
        return (*ptr)(std::forward< Args >(args)...);
    }
    ~Function() {
        if (ptr)delete ptr;
    }
};
void foo(int n, Function<void()>& call_back) {
    int sum = 0;
    for (int i = 1; i <= n; i++)sum += i;
    call_back = [=]() {
        cout << "sum  from 1"<<" to "<<n <<" is " << sum << endl;
    };
}
int main()
{
    srand(time(NULL));
    vector<Function<void()>>func(3);
    for (auto &f:func) {
        foo(rand(), f);
    }
    Function<int(int)> fib = [&](int n) {
        if (n == 0 || n == 1)return 1;
        return fib(n - 1) + fib(n - 2);
    };
    for (int i = 0; i < 10; i++)cout << fib(i) << " ";
    cout << endl;
    for (auto& f : func) {
        f();
    }
}