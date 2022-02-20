class Solution {
public:
    bool isOneBitCharacter(const vector<int> &bits) {
        auto sz = bits.size();
        int idx = 0;
        while (idx + 1 < sz) {
            if (bits[idx] == 1)
                ++idx;
            ++idx;
        }
        return idx == sz - 1;
    }
};

