class Solution {
public:
    int peakIndexInMountainArray(const vector<int> &arr) {
        auto sz = arr.size();
        int left = 0, right = sz - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int vl, v, vr;
            vl = mid == 0 ? -1 : arr[mid - 1];
            v = arr[mid];
            vr = mid == sz - 1 ? -1 : arr[mid + 1];
            if (vl < v && v < vr)
                left = mid + 1;
            else if (vl > v && v > vr)
                right = mid - 1;
            else
                return mid;
        }
        return left;
    }
};
