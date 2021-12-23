#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename Iter>
void mergeTwo(Iter iter_first, Iter iter_mid, Iter iter_last);

template<typename RandomAccessIter>
void mergeSort(RandomAccessIter iter_first, RandomAccessIter iter_last) {
    if (iter_first == iter_last)
        return;
    if (iter_last - iter_first == 1)
        return;
    RandomAccessIter iter_mid = iter_first + (iter_last - iter_first) / 2;
    mergeSort(iter_first, iter_mid);
    mergeSort(iter_mid, iter_last);
    mergeTwo(iter_first, iter_mid, iter_last);
}

template<typename Iter>
void mergeTwo(Iter iter_first, Iter iter_mid, Iter iter_last) {
    Iter i1 = iter_first, i2 = iter_mid;
    vector<typename std::iterator_traits<Iter>::value_type> tmp_vec;
    tmp_vec.reserve(iter_last - iter_first);
    while (i1 < iter_mid && i2 < iter_last) {
        if (*i1 < *i2) {
            tmp_vec.push_back(*i1);
            ++i1;
        } else {
            tmp_vec.push_back(*i2);
            ++i2;
        }
    }
    while (i1 < iter_mid)
        tmp_vec.push_back(*i1++);
    while (i2 < iter_last)
        tmp_vec.push_back(*i2++);
    copy(tmp_vec.begin(), tmp_vec.end(), iter_first);
}

struct TestSortStruct {
public:
    TestSortStruct(int a, int b)
            : a(a), b(b) {}

    int a;
    int b;
};

bool operator<(const TestSortStruct &lhs, const TestSortStruct &rhs) {
    return lhs.a < rhs.a || (lhs.a == rhs.a && lhs.b < rhs.b);
}

int main() {
    vector<int> v1{1, 1, 4, 5, 1, 4};
    mergeSort(v1.begin(), v1.end());
    cout << "int sort" << endl;
    for (auto i: v1)
        cout << i << " ";
    cout << endl;
    cout << "float sort" << endl;
    vector<float> v2{-1.1, 0.11, 4.23, 3.14, 7.77, -10.12};
    mergeSort(v2.begin(), v2.end());
    for (auto i: v2)
        cout << i << " ";
    cout << endl;
    cout << "custom type sort" << endl;
    vector<TestSortStruct> v3{TestSortStruct(1, 1), TestSortStruct(1, 2), TestSortStruct(1, 1), TestSortStruct(2, 3),
                           TestSortStruct(-1, 0), TestSortStruct(-7, 1), TestSortStruct(10, 11)};
    mergeSort(v3.begin(), v3.end());
    for (auto &i: v3)
        cout << i.a << " " << i.b << endl;
    return 0;
}

