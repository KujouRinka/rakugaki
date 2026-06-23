class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0;
        int cur = 0;
        for (auto g : gain) {
            cur += g;
            ret = max(ret, cur);
        }
        return ret;
    }
};

