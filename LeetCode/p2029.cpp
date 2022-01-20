class Solution {
public:
    bool stoneGameIX(vector<int> &stones) {
        int tp[3] = {0};
        for (int i: stones)
            ++tp[i % 3];
        if (tp[0] % 2 == 0)
            return tp[1] != 0 && tp[2] != 0;
        return abs(tp[1] - tp[2]) > 2;
    }
};
    
