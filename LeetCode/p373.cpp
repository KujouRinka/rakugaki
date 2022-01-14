class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        auto f = [&nums1, &nums2](const pair<int, int> &l, const pair<int, int> &r) -> bool {
            return nums1[l.first] + nums2[l.second] > nums1[r.first] + nums2[r.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> hp(f);
        for (int i = nums1.size() - 1; i >= 0; --i)
            hp.push({i, 0});
        vector<vector<int>> result;
        for (int i = 0; i < k && !hp.empty(); ++i) {
            auto[m, n] = hp.top();
            hp.pop();
            result.push_back({nums1[m], nums2[n]});
            if (n + 1 < nums2.size())
                hp.push({m, n + 1});
        }
        return result;
    }
};

