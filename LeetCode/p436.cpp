class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<pair<int, int>> find_vec;
        find_vec.reserve(intervals.size());
        for (int i = 0; i < intervals.size(); ++i)
            find_vec.emplace_back(intervals[i][0], i);
        sort(find_vec.begin(), find_vec.end());
        vector<int> result;
        result.reserve(intervals.size());
        for (auto &v: intervals) {
            int right = v[1];
            pair<int, int> p = {right, 1};
            auto it = lower_bound(
                find_vec.begin(), find_vec.end(),
                p, [](auto &p1, auto &p2) { return p1.first < p2.first; }
            );
            result.push_back(it == find_vec.end() ? -1 : it->second);
        }

        return result;
    }
};

