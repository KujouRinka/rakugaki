class Solution {
public:
    int maxProfit(const vector<int> &prices) {
        int profit = 0;
        int left_min = 0x7fffffff;
        for (int i: prices) {
            profit = max(profit, i - left_min);
            left_min = min(left_min, i);
        }
        return profit;
    }
};

