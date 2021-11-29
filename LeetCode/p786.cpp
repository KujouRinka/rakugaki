class Solution {
public:
    vector<int> kthSmallestPrimeFraction(const vector<int> &arr, int k) {
        vector<pair<int, int>> pv;
        int sz = arr.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                pv.emplace_back(arr[i], arr[j]);
            }
        }
        sort(pv.begin(), pv.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
            return lhs.second * rhs.first < lhs.first * rhs.second;
        });
        return {pv[k - 1].first, pv[k - 1].second};
    }
};
