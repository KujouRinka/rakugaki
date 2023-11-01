class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
    map<int, int> m1;
    for_each(flowers.begin(), flowers.end(), [&m1](auto &v) {
      ++m1[v[0]];
      --m1[v[1] + 1];
    });
    map<int, int> m2;
    m2.insert({-1, 0});
    for_each(m1.begin(), m1.end(), [&m2](auto &p) {
      m2.insert({p.first, p.second + prev(m2.end())->second});
    });
    return accumulate(people.begin(), people.end(), vector<int>(), [&m2](auto v, int query) {
      v.push_back(prev(m2.upper_bound(query))->second);
      return std::move(v);
    });
  }
};

