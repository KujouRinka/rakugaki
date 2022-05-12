class Solution {
public:
    int translateNum(int num) {
        if (num == 0)
            return 1;
        vector<int> data;
        while (num > 0) {
            data.push_back(num % 10);
            num /= 10;
        }
        reverse(data.begin(), data.end());
        vector<int> dp(data.size());
        dp[0] = 1;
        for (int i = 1; i < data.size(); ++i) {
            dp[i] += dp[i - 1];
            int d = data[i - 1] * 10 + data[i];
            if (d >= 10 && d < 26)
                dp[i] += i > 1 ? dp[i - 2] : 1;
        }
        return dp.back();
    }
};

