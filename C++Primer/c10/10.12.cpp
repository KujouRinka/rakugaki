//
// Created by KujouRinka on 2021/3/30.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Sales_data {
public:
    string getIsbn();

    Sales_data() = default;
    explicit Sales_data(string newIsbn) : isbn(newIsbn) {}

private:
    string isbn;
};

string Sales_data::getIsbn() {
    return isbn;
}

bool cmp(Sales_data &a, Sales_data &b) {
    return a.getIsbn() < b.getIsbn();
}

int main() {
    Sales_data book1("978-7-121-15535-2");
    Sales_data book2("978-7-115-44535-3");
    Sales_data book3("978-7-04-050694-5");

    vector<Sales_data> v{book1, book2, book3};
    sort(v.begin(), v.end(), cmp);

    for (auto &i : v)
        cout << i.getIsbn() << endl;
}
