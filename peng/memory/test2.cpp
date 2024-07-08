#include <iostream>
#include <unistd.h>

int main() {
    long line_size = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    if (line_size == -1) {
        std::cerr << "Error getting cache line size" << std::endl;
    } else {
        std::cout << "L1 cache line size: " << line_size << " bytes" << std::endl;
    }
    return 0;
}
