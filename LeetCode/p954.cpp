class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> num_map;
        set<int> num_set;
        for (int i: arr) {
            ++num_map[i];
            num_set.insert(i);
        }
        for (int i: num_set) {
            if (i < 0) {
                if ((i & 1) && num_map[i])
                    return false;
                if (num_map[i] > num_map[i / 2])
                    return false;
                num_map[i / 2] -= num_map[i];
                num_map[i] = 0;
            } else if (i > 0) {
                 if (num_map[i] > num_map[i * 2])
                     return false;
                 num_map[i * 2] -= num_map[i];
                 num_map[i] = 0;
            } else {
                if (num_map[0] & 1)
                    return false;
            }
        }
        return true;
    }
};

