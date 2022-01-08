class Solution {
public:
    vector<int> grayCode(int n) {
        int sz = 1 << n;
        vector<int> vec(sz);
        for (int i = 0; i < sz; ++i)
            vec[i] = (i >> 1) ^ i;
        return vec;
    }
};

