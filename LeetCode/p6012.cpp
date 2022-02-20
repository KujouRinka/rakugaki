class Solution {
public:
    int countEven(int num) {
        int result = 0;
        for (int i = 2; i <= num; ++i) {
            if (f(i))
                ++result;
        }
        return result;
    }

private:
    bool f(int n) {
        int s = 0;
        while (n != 0) {
            s += n % 10;
            n /= 10;
        }
        return (s & 1) == 0;
    }
};

