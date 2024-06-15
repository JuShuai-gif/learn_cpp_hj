#include <memory>
#include <vector>
#include <iostream>

// 简单的自定义分配器
template <typename T>
class SimpleAllocator {
public:
    using value_type = T;

    SimpleAllocator() = default;

    template <typename U>
    constexpr SimpleAllocator(const SimpleAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements." << std::endl;
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t) noexcept {
        std::cout << "Deallocating." << std::endl;
        ::operator delete(p);
    }
};

template <typename T, typename U>
bool operator==(const SimpleAllocator<T>&, const SimpleAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const SimpleAllocator<T>&, const SimpleAllocator<U>&) { return false; }

int main() {
    std::vector<int, SimpleAllocator<int>> v(5, 10);
    for (int n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
