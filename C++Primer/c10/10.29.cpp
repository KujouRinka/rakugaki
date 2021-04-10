#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    vector<string> vec(10);
    fstream fs("read.in");
    istream_iterator<string> in(fs), eof;
    copy(in, eof, vec.begin());
    for (auto &i : vec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
