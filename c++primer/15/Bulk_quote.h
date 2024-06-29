#pragma once
#include <iostream>
#include <string>
#include "Quote.h"

class Bulk_quote : public Quote {
public:
    double net_price(std::size_t n) const override {
        std::cout << "调用 Bulk_quote 的 net_price\n";
        // 假设打折策略
        if (n >= min_qty) {
            return n * (1 - discount) * price;
        } else {
            return n * price;
        }
    }

    void print() {
        std::cout << "Book_quote 特有的函数\n";
    }

private:
    std::size_t min_qty = 10; // 假设的最低折扣数量
    double discount = 0.1;    // 假设的折扣率
};
