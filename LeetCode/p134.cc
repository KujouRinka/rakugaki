class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int begin = 0;
    int end = 0;
    int remain = 0;
    bool looped = false;
    while (begin < gas.size()) {
      while (remain >= 0 && !(end == begin && looped)) {
        remain += gas[end];
        remain -= cost[end];
        if (++end == gas.size()) {
          end = 0;
          looped = true;
        }
      }

      if (remain >= 0 && end == begin && looped) {
        return begin;
      }
      remain -= gas[begin];
      remain += cost[begin++];
    }
    return -1;
  }
};
