class Solution {
public:
    int largestSumAfterKNegations(const vector<int> &nums, int k) {
        vector<int> tmp(nums);
        auto f = [&tmp](int a, int b) -> bool {
            return tmp[a] > tmp[b];
        };
        priority_queue<int, vector<int>, decltype(f)> hp(f);
        int sz = tmp.size();
        for (int i = 0; i < sz; ++i)
            hp.push(i);
        int top;
        for (; k > 0; --k) {
            top = hp.top();
            if (tmp[top] >= 0)
                break;
            hp.pop();
            tmp[top] = -tmp[top];
            hp.push(top);
        }

        if (k & 1) {
            tmp[hp.top()] = -tmp[hp.top()];
        }
        return accumulate(tmp.begin(), tmp.end(), 0);
    }
};
