class ArrTree {
public:
    ArrTree(const vector<int> &vec) : _data(vec.size()) {
        for (int i = 0; i < _data.size(); ++i) {
            _data[i] += vec[i];
            int parent = i + lowbit(i + 1);
            if (parent < _data.size())
                _data[parent] += _data[i];
        }
    }

    void add(int idx, int delta) {
        while (idx < _data.size()) {
            _data[idx] += delta;
            idx += lowbit(idx + 1);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx >= 0) {
            sum += _data[idx];
            idx -= lowbit(idx + 1);
        }
        return sum;
    }

    int lowbit(int x) {
        return x & -x;
    }

private:
    vector<int> _data;
};

class NumArray {
public:
    NumArray(const vector<int> &nums) : _raw(nums), _at(nums) {}

    void update(int index, int val) {
        _at.add(index, val - _raw[index]);
        _raw[index] = val;
    }

    int sumRange(int left, int right) {
        return _at.query(right) - _at.query(left - 1);
    }

private:
    vector<int> _raw;
    ArrTree _at;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

