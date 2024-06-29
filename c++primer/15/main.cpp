#include "Quote.h"
#include "Bulk_quote.h"
#include "Book_quote.h"
#include <memory>

void print(const std::shared_ptr<Quote> item) {
    std::size_t n{12};
    item->net_price(n);
    std::cout << "1\n";
}

int main() {
    std::shared_ptr<Quote> quote_ptr = std::make_shared<Quote>();
    std::shared_ptr<Quote> bulk_quote_ptr = std::make_shared<Bulk_quote>();
    std::shared_ptr<Quote> book_quote_ptr = std::make_shared<Book_quote>();
    bulk_quote_ptr->net_price(15);
    book_quote_ptr->net_price(20);

    // print(quote);
    // print(bulk_quote); // 这里添加对 Bulk_quote 的调用
    return 0;
}
