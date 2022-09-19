class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        int sum = 0;
        int left = target;
        int right = target;
        // ensure sum between left and right less-equal than target
        while (left > 0) {
            sum += left;
            if (sum == target && left < right)
                result.emplace_back(make(left, right));
            --left;
            while (sum > target)
                sum -= right--;
        }
        return {result.rbegin(), result.rend()};
    }

private:
    vector<int> make(int l, int r) {
        vector<int> v;
        v.reserve(r - l + 1);
        for (int i = l; i <= r; ++i)
            v.push_back(i);
        return std::move(v);
    }
};

