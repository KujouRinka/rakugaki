class Solution {
public:
    int sumNums(int n) {
        bool x = n > 1 && sumNums(n - 1) > 0;
        res += n;
        return res;
    }

private:
    int res = 0;
};

