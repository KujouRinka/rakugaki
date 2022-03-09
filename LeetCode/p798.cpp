class Solution {
public:
    int bestRotation(const vector<int> &nums) {
        _sz = nums.size();
        _ps_interval = vector<int>(_sz);
        for (int i = 0; i < _sz; ++i) {
            if (nums[i] > i) {
                addI(i + 1, i + _sz - nums[i]);
            } else {
                addI(0, i - nums[i]);
                addI(i + 1, _sz - 1);
            }
        }
        partial_sum(_ps_interval.begin(), _ps_interval.end(), _ps_interval.begin());
        int max_idx = 0;
        int max_v = -1;
        for (int i = 0; i < _sz; ++i) {
            if (_ps_interval[i] > max_v) {
                max_v = _ps_interval[i];
                max_idx = i;
            }
        }
        return max_idx;
    }

private:
    int _sz;
    vector<int> _ps_interval;

    void addI(int left, int right) {
        if (right < left)
            return;
        ++_ps_interval[left];
        if (right + 1 < _sz)
            --_ps_interval[right + 1];
    }
};

