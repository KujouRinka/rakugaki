class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int sz = arr.size();
        int sum = 0;
        vector<int> partialSum(sz + 1);
        partial_sum(arr.begin(), arr.end(), partialSum.begin() + 1);
        for (int i = 1; i <= sz; i += 2) {
            for (int j = 0; j + i <= sz; ++j) {
                sum += partialSum[j + i] - partialSum[j];
            }
        }
        return sum;
    }
};
