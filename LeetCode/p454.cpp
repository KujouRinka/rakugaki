class Solution {
public:
    int fourSumCount(const vector<int> &nums1, const vector<int> &nums2,
                     const vector<int> &nums3, const vector<int> &nums4) {
        unordered_map<int, int> sum_map;
        for (int i: nums1)
            for (int j: nums2)
                ++sum_map[i + j];
        int count = 0;
        for (int i: nums3)
            for (int j: nums4)
                if (sum_map.count(-i - j))
                    count += sum_map[-i - j];
        return count;
    }
};

