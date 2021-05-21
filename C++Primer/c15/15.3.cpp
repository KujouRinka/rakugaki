#include <iostream>
#include <string>

class Quote {

public:

    Quote() = default;

    Quote(const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) {}

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual ~Quote() = default;

private:

    std::string bookNo;

protected:

    double price = 0.0;

};

class Bulk_quote : public Quote {

public:

    Bulk_quote() = default;

    Bulk_quote(const std::string &, double, std::size_t, double);

    double net_price(std::size_t) const override;

private:

    std::size_t num_qty = 0;
    double discount = 0.0;

};

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << n << " total due: " << ret << std::endl;
    return ret;
}

void f(Quote &q) {

}

int main() {
    Bulk_quote b1;

    return 0;
}
