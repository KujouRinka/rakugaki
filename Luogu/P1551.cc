#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  int person, link, ask;
  cin >> person >> link >> ask;
  vector<int> relation(person + 1);
  for (int i = 0; i < relation.size(); ++i)
    relation[i] = i;

  function<int(int)> query;
  query = [&relation, &query](int x) -> int {
    if (relation[x] == x)
      return x;
    relation[x] = query(relation[x]);
    return relation[x];
  };

  for (int i = 0; i < link; ++i) {
    int x, y;
    cin >> x >> y;
    relation[query(x)] = relation[query(y)];
  }
  for (int i = 0; i < ask; ++i) {
    int x, y;
    cin >> x >> y;
    cout << (query(x) == query(y) ? "Yes" : "No") << endl;
  }
  return 0;
}

