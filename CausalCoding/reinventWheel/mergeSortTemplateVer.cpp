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

