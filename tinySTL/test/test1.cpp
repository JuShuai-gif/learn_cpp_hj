#include <iostream>
#include <memory>
#include <type_traits>

class NonTrivial {
public:
    NonTrivial() {
        std::cout << "NonTrivial constructor called" << std::endl;
    }
    ~NonTrivial() {
        std::cout << "NonTrivial destructor called" << std::endl;
    }
};

template <class Ty>
void destroy_one(Ty *, std::true_type) {
    // 对于平凡可销毁的类型，不需要做任何事情
}

template <class Ty>
void destroy_one(Ty *pointer, std::false_type) {
    if (pointer != nullptr) {
        pointer->~Ty(); // 调用对象的析构函数
    }
}

template <class ForwardIter>
void destroy_cat(ForwardIter, ForwardIter, std::true_type) {
    // 对于平凡可销毁的类型，不需要做任何事情
}

template <class ForwardIter>
void destroy_cat(ForwardIter first, ForwardIter last, std::false_type) {
    for (; first != last; ++first)
        destroy(&*first); // 递归调用 destroy 来销毁每个对象
}

template <class Ty>
void destroy(Ty *pointer) {
    destroy_one(pointer, std::is_trivially_destructible<Ty>{});
}

template <class ForwardIter>
void destroy(ForwardIter first, ForwardIter last) {
    destroy_cat(first, last, std::is_trivially_destructible<typename std::iterator_traits<ForwardIter>::value_type>{});
}

template<class T1,class T2>
void functionDependingOnType() {
    // 使用 std::true_type 来表示某个条件为真
    if constexpr (std::is_same<T1, T2>::value) {
        // 这个分支将在编译时被选择，因为 std::is_same<int, int> 的结果是 std::true_type
    }
}

int main() {
    const size_t size = 3;
    // 分配原始内存
    NonTrivial* array = static_cast<NonTrivial*>(operator new[](size * sizeof(NonTrivial)));

    // 构造对象
    for (size_t i = 0; i < size; ++i) {
        ::new (array + i) NonTrivial();
    }

    // 销毁对象
    destroy(array, array + size);

    // 释放内存
    operator delete[](array);

    if constexpr(std::is_same<int,float>::value)
    {
        std::cout << "same\n";
    }
    else{
        std::cout << "not same\n";
    }

    return 0;
}
