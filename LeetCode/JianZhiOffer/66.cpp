class Solution {
public:
    vector<int> constructArr(const vector<int> &a) {
        vector<int> result(a.size(), 1);
        int tmp1 = 1, tmp2 = 1;
        for (int i = 0; i < a.size(); ++i) {
            result[i] *= tmp1;
            result[a.size() - i - 1] *= tmp2;
            tmp1 *= a[i];
            tmp2 *= a[a.size() - i - 1];
        }
        return result;
    }
};

