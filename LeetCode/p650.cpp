class Solution {
public:
    int minSteps(int n) {
        int cnt = 0;
        if (n == 1)
            return 0;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                n /= i;
                cnt += i;
            }
        }
        return cnt + ((n == 1) ? 0 : n);
    }
};
