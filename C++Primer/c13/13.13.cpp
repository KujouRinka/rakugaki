#include <iostream>
#include <vector>

using namespace std;

class X {
public:
    X() { cout << "constructor" << endl; }

    X(const X &) { cout << "copy constructor" << endl; }

    X &operator=(const X &rhs);

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


void f1(X x) {

}

void f2(X &x) {

}

int main() {
    cout << "local var: " << endl;
    X x;
    cout << endl;

    cout << "non-reference parameter passing: " << endl;
    f1(x);
    cout << endl;

    cout << "reference parameter passing: " << endl;
    f2(x);
    cout << endl;

    cout << "dynamic allocation: " << endl;
    X *px = new X;
    cout << endl;

    cout << "add to container: " << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;

    cout << "release obj: " << endl;
    delete px;
    cout << endl;

    cout << "indirectly init and assignment: " << endl;
    X y = x;
    y = x;
    cout << endl;

    cout << "prog exit: " << endl;
    return 0;
}

/*
    最后有三次 destructor，为 x, y 和 vector 中的 x 的析构函数
*/