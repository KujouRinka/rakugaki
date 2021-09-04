class Solution {
    const static int mod = 1e9 + 7;
public:
    int fib(int n) {
		if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int a = 0, b = 1;
        int r;
        for (int i = 1; i < n; ++i) {
            r = (a + b) % mod;
            a = b;
            b = r;
        }
        return r;
    }
};
