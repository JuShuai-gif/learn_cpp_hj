#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1,2,3,4,5,6};
    std::vector<int>::iterator ite;
    ite = std::find(v.begin(),v.end(),10);
    
    return 0;
}