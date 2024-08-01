#include <deque>
#include "deque.h"

#include "test.h"

int main() {
    std::cout << "[===============================================================]" << std::endl;
    std::cout << "[----------------- Run container test : deque ------------------]" << std::endl;
    std::cout << "[-------------------------- API test ---------------------------]" << std::endl;
    int a[] = {1, 2, 3, 4, 5};
    mystl::deque<int> d1;
    mystl::deque<int> d2(5);
    mystl::deque<int> d3(5, 1);
    mystl::deque<int> d4(a, a + 5);
    mystl::deque<int> d5(d2);
    mystl::deque<int> d6(std::move(d2));
    mystl::deque<int> d7;
    d7 = d3;
    mystl::deque<int> d8;
    d8 = std::move(d3);
    mystl::deque<int> d9{1, 2, 3, 4, 5, 6, 7, 8, 9};
    mystl::deque<int> d10;
    d10 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    FUN_AFTER(d1, d1.assign(5, 1));
    FUN_AFTER(d1, d1.assign(8, 8));
    return 0;
}
