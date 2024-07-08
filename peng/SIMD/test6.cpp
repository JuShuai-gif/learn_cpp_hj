#include <array>
int func(){
    std::array<int,10> arr;
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
    }
    int ret = 0;
    for (int i = 0; i < 100; i++)
    {
        ret += arr[i];
    }
    return ret;    
}