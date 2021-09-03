class Solution {
private:
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

    void find(vector<int> &vec, int left, int right, int k) {
        int pivot = partition(vec, left, right);
        if (pivot == k - 1)
            return;

        if (pivot < k - 1)
            find(vec, pivot + 1, right, k);
        else
            find(vec, left, pivot - 1, k);
    }

public:
    vector<int> smallestK(vector<int> &arr, int k) {
        if (k == 0)
            return {};
        find(arr, 0, arr.size() - 1, k);
        return {arr.begin(), arr.begin() + k};
    }
};
