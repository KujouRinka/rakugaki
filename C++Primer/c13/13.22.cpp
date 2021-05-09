#include <iostream>
#include <string>

using namespace std;

class HasPtr {

public:
    HasPtr() = default;

    HasPtr(const string &is = string()) :
            integer(0), sPtr(new string(is)) {}

    HasPtr(const HasPtr &origin) {
        integer = origin.integer;
        sPtr = new string(*origin.sPtr);
    }

    HasPtr &operator=(const HasPtr &rhs);

    HasPtr &operator=(const string &rhs);

    string operator*();

    ~HasPtr() { delete sPtr; }

private:
    int integer;
    string *sPtr;
};

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new string(*rhs.sPtr);
    delete sPtr;
    sPtr = newp;
    integer = rhs.integer;
    return *this;
}

HasPtr &HasPtr::operator=(const string &rhs) {
    auto newp = new string(rhs);
    delete sPtr;
    sPtr = newp;
    return *this;
}

string HasPtr::operator*() {
    return *sPtr;
}

int main() {
    HasPtr h("hello");
    HasPtr h2(h);
    HasPtr h3 = h;

    h2 = "Hello";
    h3 = "hello world";

    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;

    return 0;
}
