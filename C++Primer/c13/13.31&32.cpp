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

    HasPtr &operator=(const HasPtr &rhs);

    HasPtr &operator=(HasPtr &&rhs) noexcept;

    // not so good
    // HasPtr &operator=(HasPtr rhs);

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
    
    void free();
};

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if (--*use == 0)
        free();
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
    if (this != &rhs) {
        if (--*use == 0)
            free();
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;

        rhs.ps = nullptr;
        rhs.i = 0;
        rhs.use = nullptr;
    }
    return *this;
}

// not so good
// HasPtr &HasPtr::operator=(HasPtr rhs) {
//     swap(*this, rhs);
//     return *this;
// }

HasPtr &HasPtr::operator=(const string &s) {
    auto newp = new string(s);
    if (--*use == 0)
        free();
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

void HasPtr::free() {
    delete ps;
    delete use;
}

HasPtr::~HasPtr() {
    if (--*use == 0)
        free();
}

void swap(HasPtr &lrs, HasPtr &rhs) {
    swap(lrs.ps, rhs.ps);
    swap(lrs.i, rhs.i);
}

int main() {
    HasPtr h("hello");
    HasPtr h2;
    h = std::move(h);
    cout << *h;

    return 0;
}
