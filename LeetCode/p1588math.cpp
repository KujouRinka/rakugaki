class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int sz = arr.size();
        int sum = 0;
        for (int i = 0; i < sz; ++i) {
            int left = i, right = sz - left - 1;
            int left_even = left / 2 + 1, left_odd = (left + 1) / 2;
            int right_even = right / 2 + 1, right_odd = (right + 1) / 2;
            sum += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return sum;
    }
};
