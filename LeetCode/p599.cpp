class Solution {
public:
    vector<string> findRestaurant(const vector<string> &list1, const vector<string> &list2) {
        unordered_map<string, int> _map;
        for (int i = 0; i < list1.size(); ++i)
            _map.insert({list1[i], i});
        vector<string> r;
        int min_idx = 0x7fffffff;
        for (int i = 0; i < list2.size(); ++i) {
            if (_map.count(list2[i])) {
                int idx_sum = i + _map[list2[i]];
                if (idx_sum < min_idx) {
                    min_idx = idx_sum;
                    r.clear();
                    r.push_back(list2[i]);
                } else if (idx_sum == min_idx) {
                    r.push_back(list2[i]);
                }
            }
        }
        return r;
    }
};

