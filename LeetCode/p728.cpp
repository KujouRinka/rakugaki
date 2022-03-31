class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for (int i = left; i <= right; ++i) {
            if (isSelfDividing(i))
                v.push_back(i);
        }
        return v;
    }

private:
    static bool isSelfDividing(int i) {
        int t = i;
        while (t > 0) {
            if (t % 10 == 0 || i % (t % 10))
                return false;
            t /= 10;
        }
        return true;
    }
};

