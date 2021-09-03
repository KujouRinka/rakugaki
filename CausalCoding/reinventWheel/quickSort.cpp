#include <vector>

using namespace std;

int partition(vector<int> &vec, int left, int right) {
    int pivot = vec[left];
    while (left < right) {
        while (left < right && vec[right] > pivot)
            --right;
        vec[left] = vec[right];
        while (left < right && vec[left] <= pivot)
            ++left;
        vec[right] = vec[left];
    }
    vec[left] = pivot;
    return left;
}

void quickSort(vector<int> &vec, int left, int right) {
    if (left >= right)
        return;

    int pivot = partition(vec, left, right);

    quickSort(vec, left, pivot - 1);
    quickSort(vec, pivot + 1, right);
}
