#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) :
            ps(new string(s)), i(0) {}

    HasPtr(const HasPtr &HP) :
            ps(new string(*HP.ps)), i(HP.i) {}

    HasPtr &operator=(const HasPtr &rhs);

private:
    string *ps;
    int i;
};

HasPtr &
HasPtr::operator=(const HasPtr &rhs) {
    auto nps = new string(*rhs.ps);
    delete ps;
    ps = nps;
    i = rhs.i;
    return *this;
}
