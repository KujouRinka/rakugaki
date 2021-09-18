class Solution {
public:
    int minSteps(int n) {
        int cnt = 0;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {	// 分解因式
                n /= i;
                cnt += i;
            }
        }
        return cnt + ((n == 1) ? 0 : n);	// 若 n== 1，则 n 不为素数
    }
};
