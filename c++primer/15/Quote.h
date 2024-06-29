#pragma once
#include <iostream>
#include <string>

class Quote
{
public:
    std::string isbn() const { return bookNo; }
    virtual ~Quote() = default;
    virtual double net_price(std::size_t n) const {
        std::cout << "调用 Quote 的 net_price\n";
        return n * price; // 假设每本书的价格为price
    }

    void print(){
        std::cout << "基类特有的函数\n";
    }

private:
    std::string bookNo;
protected:
    double price = 0.0; // 假设每本书的价格
};
