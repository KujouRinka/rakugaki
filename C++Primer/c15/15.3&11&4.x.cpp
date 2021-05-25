#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>

class Quote {
public:
    Quote(const std::string &book = "", double sales_price = 0.0) :
            bookNo(book), price(sales_price) {}
    Quote(const Quote &rhs) :
            bookNo(rhs.bookNo), price(rhs.price) {}
    Quote(Quote &&rhs) = default;
    virtual Quote *clone() const &{ return new Quote(*this); }
    virtual Quote *clone() &&{ return new Quote(std::move(*this)); }

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
    Disc_quote(Disc_quote &&rhs) = default;

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
    Bulk_quote(Bulk_quote &&rhs) = default;
    Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }

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
    Limited_quote(Limited_quote &&rhs) = default;
    Limited_quote *clone() const & override { return new Limited_quote(*this); }
    Limited_quote *clone() && override { return new Limited_quote(std::move(*this)); }

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

class Basket {
public:
    Basket() = default;

    void add_item(const Quote &sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    void add_item(const std::shared_ptr<Quote> &sale) {
        items.insert(sale);
    }
    double total_receipt(std::ostream &os) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;
    for (auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it))
        sum += print_total(os, **it, items.count(*it));
    os << "Total Sale: " << sum << std::endl;
    return sum;
}

int main() {
    Quote b1("123456-2345", 30.5);
    Bulk_quote b2("114514-2333", 30.5, 50, 0.2);
    Limited_quote b3("170001-1024", 30.5, 50, 0.2);
    Basket basket;
    for (int i = 0; i < 100; ++i) {
        basket.add_item(b1);
        basket.add_item(b2);
        basket.add_item(b3);
    }
    basket.total_receipt(std::cout);

    return 0;
}
