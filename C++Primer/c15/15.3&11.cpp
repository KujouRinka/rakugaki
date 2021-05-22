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

    virtual void debug() const {
        std::cout << "bookNO=" << bookNo << " price=" << price << std::endl;
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

    Bulk_quote(const std::string &book, double p,
               std::size_t qty, double disc) :
            Quote(book, p), min_qty(qty), discount(disc) {};

    double net_price(std::size_t cnt) const override;

    void debug() const override {
        Quote::debug();
        std::cout << "min_qty=" << min_qty << " discount=" << discount << std::endl;
    }

private:

    std::size_t min_qty = 0;
    double discount = 0.0;

};

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

class Limited_quote : public Quote {

public:

    Limited_quote() = default;

    Limited_quote(const std::string &book, double p,
                  std::size_t qty, double disc) :
            Quote(book, p), min_qty(qty), discount(disc) {}

    double net_price(std::size_t cnt) const override;

    void debug() const override {
        Quote::debug();
        std::cout << "min_qty=" << min_qty << " discount=" << discount << std::endl;
    }

private:

    std::size_t min_qty;
    double discount;

};

double Limited_quote::net_price(std::size_t cnt) const {
    if (cnt <= min_qty)
        return cnt * (1 - discount) * price;
    else
        return ((1 - discount) * min_qty + (cnt - min_qty)) * price;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " total due: " << ret << std::endl;
    return ret;
}

int main() {
    Quote b1("123456-2345", 30.5);
    Bulk_quote b2("114514-2333", 30.5, 50, 0.2);
    Limited_quote b3("170001-1024", 30.5, 50, 0.2);
    print_total(std::cout, b1, 100);
    print_total(std::cout, b2, 100);
    print_total(std::cout, b3, 100);
    return 0;
}
