static std::default_random_engine e(time(nullptr));
static std::uniform_int_distribution<int> distribution(0, 0x7fffffff);

class Solution {
public:
    Solution(vector<int> &nums) : shuf(nums), ori(nums) {};

    vector<int> reset() {
        shuf = ori;
        return ori;
    }

    vector<int> shuffle() {
        int sz = shuf.size();
        for (int i = 0; i < sz; ++i) {
            int swap_idx = distribution(e) % (sz - i) + i;
            swap(shuf[i], shuf[swap_idx]);
        }
        return shuf;
    }

private:
    vector<int> shuf;
    vector<int> ori;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
