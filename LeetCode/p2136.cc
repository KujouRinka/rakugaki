class Solution {
 public:
  int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
    vector<pair<int, int>> p;
    p.reserve(plantTime.size());
    for (int i = 0; i < plantTime.size(); ++i) {
      p.emplace_back(plantTime[i], growTime[i]);
    }
    sort(p.begin(), p.end(), [](auto &l, auto &r) {
      return l.second > r.second;
    });
    int pt = 0;
    int lt = 0;
    for (auto & i : p) {
      pt += i.first;
      lt = max(lt, pt + i.second);
    }
    return max(pt, lt);
  }
};

