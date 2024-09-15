#include <iostream>
#include <vector>

template <class T>
T swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void print_vec(std::vector<int> vec) {
    for (auto &&i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// 冒泡排序
void BubbleSort(std::vector<int> &vec, int n) {
    if (n <= 1) {
        return;
    }

    bool is_warp;
    for (int i = 1; i < n; ++i) {
        is_warp = false;
        for (int j = 1; j < n - i + 1; ++j) {
            if (vec[j] < vec[j - 1]) {
                std::swap(vec[j], vec[j - 1]);
                is_warp = true;
            }
        }
        if (!is_warp)
            break;
    }
}

// 插入排序
void InsertSort(std::vector<int> &nums, int n) {
    if (n <= 1)
        return;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            std::swap(nums[j], nums[j - 1]);
        }
    }
}

// 选择排序
void SelectSort(std::vector<int> &nums, int n) {
    if (n <= 1)
        return;
    int mid;
    for (int i = 0; i < n - 1; ++i) {
        mid = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[mid]) {
                mid = j;
            }
        }
        std::swap(nums[mid], nums[i]);
    }
}

// 快排
void QuickSort(std::vector<int> &nums, int l, int r) {
    if (l + 1 >= r)
        return;
    int first = 1, last = r - 1, key = nums[first];
    while (first < last) {
        while (first < last && nums[last >= key])
            last--;

        nums[first] = nums[last];

        while (first < last && nums[first] <= key)
            first++;
        nums[last] = nums[first];
    }
    nums[first] = key;
    QuickSort(nums, 1, first);
    QuickSort(nums, first + 1, r);
}

// 归并排序


int main() {
    std::vector<int> a = {34, 6, 2, 5, 95, 4, 46, 27};
    BubbleSort(a, a.size());
    print_vec(a);

    std::vector<int> b = {34, 6, 2, 5, 95, 4, 46, 27};
    InsertSort(b, b.size());
    print_vec(b);
    return 0;
}
