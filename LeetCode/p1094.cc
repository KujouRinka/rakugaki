class Solution {
 public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    map<int, int> mp;
    for_each(trips.begin(), trips.end(), [&mp](auto &v) {
      mp[v[1]] += v[0];
      mp[v[2]] -= v[0];
    });
    int acc = 0;
    for (auto &[_, v] : mp) {
      if ((acc += v) > capacity) {
        return false;
      }
    }
    return true;
  }
};

