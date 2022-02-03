class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> dp{0, 1};
        int next = 1;
        for (int i = 2; next <= k; ++i) {
            dp.push_back(next);
            next = dp[i] + dp[i - 1];
        }
        int count = 0;
        while (k != 0) {
            auto it = upper_bound(dp.begin(), dp.end(), k) - 1;
            k -= *it;
            ++count;
        }
        return count;
    }
};

