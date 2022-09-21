#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;

void reset(vector<int> &v, int sz) {
  v.resize(sz);
  for (int i = 0; i < sz; ++i)
    v[i] = i;
}

int main() {
  int machi, road;
  function<int(int)> query;
  vector<int> relation;
  unordered_set<int> s;
  query = [&relation, &query](int x) -> int {
    if (relation[x] == x)
      return x;
    relation[x] = query(relation[x]);
    return relation[x];
  };
  while (cin >> machi >> road) {
    reset(relation, machi + 1);
    s.clear();
    for (int i = 0; i < road; ++i) {
      int x, y;
      cin >> x >> y;
      relation[query(x)] = relation[query(y)];
    }
    for (int i = 1; i <= machi; ++i)
      s.insert(query(i));
    cout << s.size() - 1 << "\n";
  }
  cout << endl;
  return 0;
}

