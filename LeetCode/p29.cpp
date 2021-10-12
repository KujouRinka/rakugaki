class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (dividend == -(1u << 31)) {
            if (divisor == dividend)
                return 1;
        }
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend == -(1u << 31))
                return 0x7fffffff;
            else
                return -dividend;
        }

        int sign = 1;
        if (dividend > 0) {
            dividend = -dividend;
            sign = -sign;
        }
        if (divisor > 0) {
            divisor = -divisor;
            sign = -sign;
        }

        int result = div(dividend, divisor) * sign;
        return result;
    }

private:
    static int div(int a, int b) {
        // a, b must be positive
        if (a - b > 0)
            return 0;
        int cnt = 1;
        int m = b;
        while (m >= -(1 << 30) && a - (m + m) <= 0) {
            cnt += cnt;
            m += m;
        }

        return cnt + div(a - m, b);
    }
};
