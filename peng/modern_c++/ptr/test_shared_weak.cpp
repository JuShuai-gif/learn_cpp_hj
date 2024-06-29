#include <iostream>
#include "shared_weak_ptr.h" // 假设上面的实现代码保存在 shared_ptr.h 文件中

int main() {
    {
        auto sp = make_shared<int>(42);
        std::cout << "SharedPtr use count: " << sp.use_count() << std::endl;

        SharedPtr<int> sp2 = sp;
        std::cout << "SharedPtr use count after copy: " << sp.use_count() << std::endl;

        WeakPtr<int> wp = sp;
        std::cout << "WeakPtr use count: " << wp.use_count() << std::endl;

        auto sp3 = wp.lock();
        std::cout << "SharedPtr use count after lock: " << sp3.use_count() << std::endl;

        sp.reset();
        std::cout << "SharedPtr use count after reset: " << sp2.use_count() << std::endl;
    }

    std::cout << "End of scope" << std::endl;
    return 0;
}
