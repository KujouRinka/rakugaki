#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::reverse_iterator re(vec.begin() + 2);
    vector<int>::reverse_iterator rb(vec.begin() + 7);
    ostream_iterator<int> out(cout, " ");
    copy(vec.begin() + 2, vec.begin() + 7, out);
    cout << endl;
    list<int> li;
    copy(rb, re, back_inserter(li));
    copy(li.begin(), li.end(), out);
    cout << endl;
    return 0;
}
