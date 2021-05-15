#include <iostream>
#include <string>

using namespace std;

class HasPtr {

    friend void swap(HasPtr &lrs, HasPtr &rhs);

public:
    HasPtr(const string &s = string()) :
            ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr(const HasPtr &p) :
            ps(p.ps), i(p.i), use(p.use) { ++*use; }

    HasPtr(HasPtr &&p) noexcept:
            ps(p.ps), i(p.i), use(p.use) { p.ps = nullptr; }

    // HasPtr &operator=(const HasPtr &rhs);

    // HasPtr &operator=(HasPtr &&rhs) noexcept;

    HasPtr &operator=(HasPtr rhs);

    HasPtr &operator=(const string &s);

    string &operator*();

    bool operator<(const HasPtr &rhs);

    bool unique();

    string *get();

    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use;
};

// HasPtr &HasPtr::operator=(const HasPtr &rhs) {
//     ++*rhs.use;
//     if (--*use == 0) {
//         delete ps;
//         delete use;
//     }
//     ps = rhs.ps;
//     use = rhs.use;
//     i = rhs.i;
//     return *this;
// }
//
// HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
//     swap(*this, rhs);
//     return *this;
// }

HasPtr &HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

HasPtr &HasPtr::operator=(const string &s) {
    auto newp = new string(s);
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = newp;
    use = new size_t(1);
    i = 0;
    return *this;
}

string &HasPtr::operator*() {
    return *ps;
}

bool HasPtr::operator<(const HasPtr &rhs) {
    return *ps < *rhs.ps;
}

bool HasPtr::unique() {
    return *use == 1;
}

string *HasPtr::get() {
    return ps;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

void swap(HasPtr &lrs, HasPtr &rhs) {
    swap(lrs.ps, rhs.ps);
    swap(lrs.i, rhs.i);
}

int main() {
    HasPtr h("hello");
    cout << "h unique: " << h.unique() << endl;
    HasPtr h2 = h;
    cout << "h unique: " << h.unique() << endl;
    h = "world";

    auto sp = h2.get();

    cout << "h: " << *h << " unique: " << h.unique() << endl;
    cout << "h2: " << *sp << " unique: " << h2.unique() << endl;
    swap(h, h2);
    h2 = h;

    cout << "h: " << *h << " unique: " << h.unique() << endl;
    cout << "h2: " << *h2 << " unique: " << h2.unique() << endl;

    return 0;
}
