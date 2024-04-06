#include <iostream>

template<typename T>
inline void hash_combine(size_t& seed,const T& val){
    seed^=std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template<typename T>
inline void hash_val(size_t& seed,const T& val){
    hash_combine(seed,val);
}
template<typename T,typename... Type>
inline void hash_val(size_t& seed,const T& val,const Type&... args){
    hash_combine(seed,val);
    hash_val(seed,args...);
}
template<typename... Types>
inline size_t hash_val(const Types&... args){
    size_t seed = 0;
    hash_val(seed,args...);
    return seed;
}




class CustomerHash
{
public:
    std::size_t operator()(const CustomerHash& c)const
    {
        return hash_val(c.fname,c.lname,c.no);
    }

    CustomerHash(std::string f,std::string l,int n):fname(f),lname(l),no(n){}
    
public:
    std::string fname{};
    std::string  lname{};
    int no{};
};

