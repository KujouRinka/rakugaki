#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    fstream fs("read.in");
    ofstream fo1("out1"), fo2("out2");
    istream_iterator<int> in(fs), eof;
    ostream_iterator<int> out1(fo1, " "), out2(fo2, "\n");
    for_each(in, eof, [&out1, &out2](int value) {
        if (value & 1) *out1++ = value;
        else *out2++ = value;
    });
    fs.close();
    fo1.close();
    fo2.close();
    return 0;
}
