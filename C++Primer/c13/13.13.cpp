#include <iostream>
#include <vector>

using namespace std;

class X {
public:
    X() { cout << "constructor" << endl; }

    X(const X &) { cout << "copy constructor" << endl; }

    X(X &&) { cout << "move constructor" << endl; }

    X &operator=(const X &rhs);

    X &operator=(X &&rhs) { cout << "move-assignment operator" << endl; return *this; }

    ~X();
};

X &
X::operator=(const X &rhs) {
    cout << "copy-assignment operator" << endl;
    return *this;
}

X::~X() {
    cout << "destructor" << endl;
}


X f1(X x) {
    return x;
}

void f2(X &x) {

}

int main() {
    cout << "local var: " << endl;
    X x;
    cout << endl;
    // constructor

    cout << "non-reference parameter passing: " << endl;
    X z = f1(x);
    z = f1(x);
    cout << endl;
    // copy constructor
    // move constructor
    // destructor

    // copy constructor
    // move constructor
    // move-assignment operator
    // destructor
    // destructor

    cout << "reference parameter passing: " << endl;
    f2(x);
    cout << endl;

    cout << "dynamic allocation: " << endl;
    X *px = new X;
    cout << endl;
    // constructor

    cout << "add to container: " << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;
    // copy constructor

    cout << "release obj: " << endl;
    delete px;
    cout << endl;
    // destructor

    cout << "indirectly init and assignment: " << endl;
    X y = x;
    y = x;
    y = std::move(x);
    cout << endl;
    // copy constructor
    // copy-assignment operator
    // move-assignment operator

    cout << "prog exit: " << endl;
    return 0;
}
