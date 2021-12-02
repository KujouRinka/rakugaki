class Solution {
public:
    vector<string> findRelativeRanks(const vector<int> &score) {
        int sz = score.size();
        vector<string> result(sz);
        map<int, int> ordered_map;
        for (int i = 0; i < sz; ++i)
            ordered_map[score[i]] = i;
        int count = 1;
        for (auto rit = ordered_map.rbegin(); rit != ordered_map.rend(); ++rit, ++count) {
            switch (count) {
                case 1:
                    result[rit->second] = "Gold Medal";
                    break;
                case 2:
                    result[rit->second] = "Silver Medal";
                    break;
                case 3:
                    result[rit->second] = "Bronze Medal";
                    break;
                default:
                    result[rit->second] = to_string(count);
            }
        }
        return result;
    }
};
