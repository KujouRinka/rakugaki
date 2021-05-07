#include <iostream>

using namespace std;

class numbered {

public:
    numbered() { mysn = seq++; }

    numbered(const numbered &n) { mysn = seq++; }

    int mysn;

private:
    static int seq;
};

void f1(const numbered n) {
    cout << n.mysn << endl;
}

void f2(const numbered &n) {
    cout << n.mysn << endl;
}

int numbered::seq = 0;

int main() {
    numbered a, b = a, c = b;
    f1(a);
    f1(b);
    f1(c);
    f2(a);
    f2(b);
    f2(c);
    return 0;
}
