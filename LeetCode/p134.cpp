class Solution {
public:
    int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
        auto sz = gas.size();
        int current = 0;
        int ps = 0;
        int ts = 0;
        for (int i = 0; i < sz; ++i) {
            ps += gas[i] - cost[i];
            ts += gas[i] - cost[i];
            if (ps < 0) {
                ps = 0;
                current = i + 1;
            }
        }
        return ts < 0 ? -1 : current;
    }
};

