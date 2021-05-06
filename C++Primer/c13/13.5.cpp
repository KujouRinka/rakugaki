#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) :
            ps(new string(s)), i(0) {}

    HasPtr(const HasPtr &HP) :
            ps(new string(*HP.ps)), i(HP.i) {}

private:
    string *ps;
    int i;
};
