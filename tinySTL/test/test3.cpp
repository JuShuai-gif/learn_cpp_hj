#include <iostream>
#include <vector>
#include <type_traits> // 包含 std::true_type 和 std::false_type

namespace mystl {
    template <typename InputIter, typename ForwardIter>
    ForwardIter copy(InputIter first, InputIter last, ForwardIter result) {
        while (first != last) {
            *result = *first;
            ++first;
            ++result;
        }
        return result;
    }

    template <typename T>
    void construct(T* ptr, const T& value) {
        new(ptr) T(value);
    }

    template <typename T>
    void destroy(T* ptr) {
        ptr->~T();
    }
}

template <class InputIter, class ForwardIter>
ForwardIter unchecked_uninit_copy(InputIter first, InputIter last, ForwardIter result, std::true_type) {
    return mystl::copy(first, last, result);
}

template <class InputIter, class ForwardIter>
ForwardIter unchecked_uninit_copy(InputIter first, InputIter last, ForwardIter result, std::false_type) {
    auto cur = result;
    try {
        for (; first != last; ++first, ++cur) {
            mystl::construct(&*cur, *first);
        }
    } catch (...) {
        for (; result != cur; --cur)
            mystl::destroy(&*cur);
    }
    return cur;
}

struct NonTrivial {
    int value;
    NonTrivial(int v) : value(v) {}
    NonTrivial(const NonTrivial& other) : value(other.value) {
        std::cout << "Copy constructor called\n";
    }
    ~NonTrivial() {
        std::cout << "Destructor called\n";
    }
};

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2(v1.size());

    unchecked_uninit_copy(v1.begin(), v1.end(), v2.begin(), std::true_type{});

    std::cout << "v2: ";
    for (int val : v2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<NonTrivial> nt1 = {NonTrivial(1), NonTrivial(2), NonTrivial(3)};
    std::vector<NonTrivial> nt2(nt1.size());

    unchecked_uninit_copy(nt1.begin(), nt1.end(), nt2.begin(), std::false_type{});

    std::cout << "nt2: ";
    for (const auto& val : nt2) {
        std::cout << val.value << " ";
    }
    std::cout << std::endl;

    return 0;
}
