class Solution {
public:
    vector<int> pancakeSort(vector<int> &arr) {
        auto sz = arr.size();
        vector<int> result;
        result.reserve((sz - 1) * 2);
        for (auto i = sz; i > 1; --i) {
            auto max_it = max_element(arr.begin(), arr.begin() + i);
            if (max_it == arr.begin() + i - 1)
                continue;
            if (max_it != arr.begin()) {
                reverse(arr.begin(), next(max_it));
                result.push_back(max_it - arr.begin() + 1);
            }
            reverse(arr.begin(), arr.begin() + i);
            result.push_back(i);
        }
        return result;
    }
};

