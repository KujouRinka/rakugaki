#include <vector>

using namespace std;

void merge(vector<int> &v, int left, int mid, int right) {
    int p1 = left, p2 = mid + 1;
    vector<int> tp;
    while (p1 <= mid && p2 <= right) {
        if (v[p1] < v[p2])
            tp.push_back(v[p1++]);
        else
            tp.push_back(v[p2++]);
    }
    while (p1 <= mid)
        tp.push_back(v[p1++]);
    while (p2 <= right)
        tp.push_back(v[p2++]);
    for (auto &i : tp)
        v[left++] = i;
}

void _mergeSort(vector<int> &v, int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    _mergeSort(v, left, mid);
    _mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}

void mergeSortInt(vector<int> &v) {
    _mergeSort(v, 0, v.size() - 1);
}
