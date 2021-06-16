#include <iostream>
#include <string>

using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t) {
    os << t;
    return os;
}

template<typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args & ... rest) {
    cout << t << ", ";
    print(os, rest...);
    return os;
}

int main() {
    print(cout, 1, "hello", string("world"), 1.5);
    return 0;
}
