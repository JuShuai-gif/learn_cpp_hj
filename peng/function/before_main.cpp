#include <iostream>
/*
__attribute((constructor))void before(){
    printf("before main 1 \n");
}

int test1(){
    std::cout << "before main 2" << std::endl;
}

static int i = test1();
*/
int a = [](){
    std::cout << "before main 3"<< std::endl;
    return 0;
}();

int main(int argc,char **argv){
    std::cout << "main function" << std::endl;
    return 0;
}