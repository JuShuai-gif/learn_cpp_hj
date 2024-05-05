/*
测试 三五法则
*/
#include <iostream>
#include <string.h>
#include <vector>

class Vector_T
{
public:
    size_t m_size{1};
    int* m_data{nullptr};

public:
    Vector_T(){}
    explicit Vector_T(size_t n){
        m_size = n;
        m_data = (int*)malloc(n * sizeof(int));
    }

    ~Vector_T(){
        free(m_data);
    }

    size_t size(){
        return m_size;
    }

    void resize(size_t size){
        m_size = size;
        m_data = (int*)malloc(size * sizeof(int));
    }

    int& operator[](size_t index){
        return m_data[index];
    }

    Vector_T(Vector_T const& other){
        std::cout << "调用拷贝构造" << std::endl;
        m_size = other.m_size;
		m_data = (int*)malloc(other.m_size * sizeof(int));
		if (m_data){
			memcpy(m_data, other.m_data, m_size * sizeof(int));
		}
		else{
			std::cout << "分配内存失败！！！" << std::endl;
		}
    }

    Vector_T& operator=(Vector_T const& other){
        std::cout << "调用拷贝赋值" << std::endl;
        m_size = other.m_size;
        m_data = (int*)realloc(m_data,m_size * sizeof(int));
        memcpy(m_data,other.m_data,m_size * sizeof(int));
        return *this;
    }


};

Vector_T global;
Vector_T foo_bar(Vector_T arg){
    Vector_T local = arg,*heap = new Vector_T(global);
    *heap = local;
    Vector_T pa[4] = {local,*heap};
    return *heap;
}

int main(){
    //std::vector<Vector_T> v(4);

    Vector_T v0(32);
    Vector_T v1(32);
    Vector_T v2(32);

    //v.insert(v.begin(),v0);
    //std::cout << v.capacity() << std::endl;
    std::cout << "***********" << std::endl;
    //v.push_back(v1);
    //std::cout << v.capacity() << std::endl;
    //v.emplace_back(v1);

    std::cout << "***********" << std::endl;
    foo_bar(v0);
    return 0;
}






