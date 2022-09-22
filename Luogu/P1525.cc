#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct AngPair {
  AngPair(int one, int two, int ang) : one(one), two(two), ang(ang) {}
  int one, two, ang;
};

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> relation(n * 2 + 1);
  function<int(int)> find;
  find = [&](int x) {
    if (relation[x] == x)
      return x;
    return relation[x] = find(relation[x]);
  };
  vector<AngPair> memo;
  memo.reserve(p);
  for (int i = 0; i < relation.size(); ++i)
    relation[i] = i;
  while (p--) {
    int o, t, a;
    cin >> o >> t >> a;
    memo.emplace_back(o, t, a);
  }
  sort(memo.begin(), memo.end(), [](auto &l, auto &r) {
    return l.ang >= r.ang;
  });
  for (auto &ang : memo) {
    if (find(ang.one) == find(ang.two) || find(ang.one + n) == find(ang.two + n)) {
      cout << ang.ang;
      return 0;
    }
    relation[find(ang.one)] = relation[find(ang.two + n)];
    relation[find(ang.two)] = relation[find(ang.one + n)];
  }
  cout << 0 << endl;
  return 0;
}

