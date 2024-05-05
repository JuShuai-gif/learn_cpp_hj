#include <iostream>
#include <stdexcept>

void fun() noexcept{
    throw std::runtime_error("the answer is: hello ");
}

int main(){
    try
    {
        fun();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}










