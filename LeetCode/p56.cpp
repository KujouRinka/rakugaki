class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (auto &interval: intervals) {
            if (result.empty()) {
                result.push_back(interval);
            } else {
                if (interval[0] <= result.back()[1]) {
                    result.back()[1] = max(result.back()[1], interval[1]);
                } else {
                    result.push_back(interval);
                }
            }
        }
        return result;
    }
};

