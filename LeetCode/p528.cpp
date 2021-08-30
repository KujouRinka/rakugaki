class Solution {
public:
    Solution(vector<int> &w)
            : d(1, 0), u(1, accumulate(w.begin(), w.end(), 0)) {
        auto it = back_inserter(d);
        partial_sum(w.begin(), w.end(), it);
    }

    int pickIndex() {
        return lower_bound(d.begin(), d.end(), u(e)) - d.begin() - 1;
    }

private:
    default_random_engine e;
    uniform_int_distribution<int> u;
    vector<int> d;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */