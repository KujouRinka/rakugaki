class RangeFreqQuery {
public:
    RangeFreqQuery(const vector<int> &arr) {
        auto sz = arr.size();
        for (int i = 0; i < sz; ++i)
            pos_map[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        auto &vec = pos_map[value];
        return lower_bound(vec.begin(), vec.end(), right + 1) - lower_bound(vec.begin(), vec.end(), left);
    }

private:
    unordered_map<int, vector<int>> pos_map;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
