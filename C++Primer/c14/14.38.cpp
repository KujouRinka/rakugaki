#include <iostream>
#include <string>
using namespace std;

class StrLenIs {

public:

    StrLenIs(int len) : len(len) {}

    bool operator()(const string &str) const { return str.length() == len; }

private:

    int len;

};
