class Solution {
    using ll = long long;

public:
    long long subArrayRanges(const vector<int> &nums) {
        auto sz = nums.size();
        vector<int> min_left(sz);
        vector<int> min_right(sz);
        vector<int> max_left(sz);
        vector<int> max_right(sz);
        stack<int> min_idx, max_idx;    // min: incr, max: desc
        for (int i = 0; i < sz; ++i) {
            while (!min_idx.empty() && nums[min_idx.top()] >= nums[i])
                min_idx.pop();
            min_left[i] = min_idx.empty() ? -1 : min_idx.top();
            min_idx.push(i);

            while (!max_idx.empty() && nums[max_idx.top()] <= nums[i])
                max_idx.pop();
            max_left[i] = max_idx.empty() ? -1 : max_idx.top();
            max_idx.push(i);
        }

        min_idx = stack<int>();
        max_idx = stack<int>();
        for (int i = sz - 1; i >= 0; --i) {
            while (!min_idx.empty() && nums[min_idx.top()] > nums[i])
                min_idx.pop();
            min_right[i] = min_idx.empty() ? sz : min_idx.top();
            min_idx.push(i);

            while (!max_idx.empty() && nums[max_idx.top()] < nums[i])
                max_idx.pop();
            max_right[i] = max_idx.empty() ? sz : max_idx.top();
            max_idx.push(i);
        }

        ll r = 0;
        for (int i = 0; i < sz; ++i) {
            r += (static_cast<ll>((max_right[i] - i) * (i - max_left[i]))
                  - static_cast<ll>((min_right[i] - i) * (i - min_left[i])))
                 * nums[i];
        }
        return r;
    }
};

