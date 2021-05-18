#include <iostream>
#include <string>

class Date {

    friend std::ostream &operator<<(std::ostream &os, const Date &rhs);

    friend std::istream &operator>>(std::istream &is, Date &rhs);

    friend bool operator==(Date &lhs, Date &rhs);

    friend bool operator!=(Date &lhs, Date &rhs);

    friend bool operator<(Date &lhs, Date &rhs);

    friend bool operator<=(Date &lhs, Date &rhs);

    friend bool operator>(Date &lhs, Date &rhs);

    friend bool operator>=(Date &lhs, Date &rhs);

public:

    Date(const int &y = 0, const int &m = 0, const int &d = 0) :
            year(y), month(m), day(d) {}

private:

    int year, month, day;

};

std::ostream &operator<<(std::ostream &os, const Date &rhs) {
    std::string sep = "\t";
    os << "year: " << rhs.year
       << sep << "month: " << rhs.month
       << sep << "day: " << rhs.day;
    return os;
}

std::istream &operator>>(std::istream &is, Date &rhs) {
    is >> rhs.year >> rhs.month >> rhs.day;
    if (!is)
        rhs = Date();
    return is;
}

bool operator==(Date &lhs, Date &rhs) {
    return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}

bool operator!=(Date &lhs, Date &rhs) {
    return !(lhs == rhs);
}

bool operator<(Date &lhs, Date &rhs) {
    return lhs.year < rhs.year ||
           (lhs.year == rhs.year && lhs.month < rhs.month) ||
           (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day);
}

bool operator<=(Date &lhs, Date &rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>(Date &lhs, Date &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(Date &lhs, Date &rhs) {
    return lhs > rhs || lhs == rhs;
}
