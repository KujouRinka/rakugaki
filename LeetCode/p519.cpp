class Solution {
public:
    Solution(int m, int n) : m(m), n(n), count(m * n), distribution(0, 0x7fffffff), e(time(nullptr)) {}

    vector<int> flip() {
        int x = distribution(e) % (count--);
        int idx = s.count(x) ? s[x] : x;
        s[x] = s.count(count) ? s[count] : count;
        return {idx / n, idx % n};
    }

    void reset() {
        count = m * n;
        s.clear();
    }

private:
    uniform_int_distribution<int> distribution;
    default_random_engine e;
    unordered_map<int, int> s;
    int count;
    int m;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
