class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int sum = 10;
        int t = 9;
        int mult = 9;
        for (int i = 2; i <= n; ++i) {
            t *= mult;
            --mult;
            sum += t;
        }
        return sum;
    }
};

