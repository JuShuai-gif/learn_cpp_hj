#include <cstdio>
#include <vector>

struct MyClass {
    std::vector<int> arr;
    int get_size() {
        return arr.size();
    }
    void grow_size(int n) {
        if (arr.size() < n) {
            arr.resize(n);
        }
    }
    void grow_size() {
        grow_size(get_size() + 1);
    }
    int get_value() {
        while (arr.size() < 1024) {
        }

        return arr[0];
    }
    void func() {
        *(int *)0x1234 = 1;
        int val = get_value();
        printf("arr[0] = %d\n", val);
    }
};
int main() {
    MyClass mc;
    mc.func();
    return 0;
}
