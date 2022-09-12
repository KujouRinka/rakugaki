#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
  list<int> l;
  unordered_map<int, list<int>::iterator> m;
  l.insert(l.begin(), 1);
  m.insert({1, l.begin()});
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int k, p;
    cin >> k >> p;
    auto it = m[k];
    advance(it, p);
    m.insert({i, l.insert(it, i)});
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int who;
    cin >> who;
    if (m.count(who)) {
      l.erase(m[who]);
      m.erase(who);
    }
  }
  for (int i : l)
    cout << i << " ";
  cout << endl;
  return 0;
}

