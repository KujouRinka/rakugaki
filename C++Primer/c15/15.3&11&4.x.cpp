#include <iostream>
#include <string>

class Quote {
public:
    Quote(const std::string &book = "", double sales_price = 0.0) :
            bookNo(book), price(sales_price) {}
    Quote(const Quote &rhs) :
            bookNo(rhs.bookNo), price(rhs.price) {}

    Quote &operator=(const Quote &rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }

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

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price,
               std::size_t qty, double disc) :
            Quote(book, price), quantity(qty), discount(disc) {}
    Disc_quote(const Disc_quote &rhs) :
            Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {}

    Disc_quote &operator=(const Disc_quote &rhs) {
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        return *this;
    }

    double net_price(std::size_t) const override = 0;

    ~Disc_quote() = default;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    // Bulk_quote(const std::string &book, double p,
    //            std::size_t qty, double disc) :
    //         Disc_quote(book, p, qty, disc) {}
    using Disc_quote::Disc_quote;
    Bulk_quote(const Bulk_quote &rhs) :
            Disc_quote(rhs) {}

    Bulk_quote &operator=(const Bulk_quote &rhs) {
        Disc_quote::operator=(rhs);
        return *this;
    }

    double net_price(std::size_t cnt) const override;
    void debug() const override {
        Quote::debug();
        std::cout << "quantity=" << quantity << " discount=" << discount << std::endl;
    }
};

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

class Limited_quote : public Disc_quote {
public:
    Limited_quote() = default;
    // Limited_quote(const std::string &book, double p,
    //               std::size_t qty, double disc) :
    //         Disc_quote(book, p, qty, disc) {}
    using Disc_quote::Disc_quote;
    Limited_quote(const Limited_quote &rhs) :
            Disc_quote(rhs) {}

    Limited_quote &operator=(const Limited_quote &rhs) {
        Disc_quote::operator=(rhs);
        return *this;
    }

    double net_price(std::size_t cnt) const override;
    void debug() const override {
        Quote::debug();
        std::cout << "quantity=" << quantity << " discount=" << discount << std::endl;
    }
};

double Limited_quote::net_price(std::size_t cnt) const {
    if (cnt <= quantity)
        return cnt * (1 - discount) * price;
    else
        return ((1 - discount) * quantity + (cnt - quantity)) * price;
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
