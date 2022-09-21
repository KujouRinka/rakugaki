#include <iostream>
#include <set>

using namespace std;

class Tree {
 public:
  Tree() = default;

  void insert(int v) {
    if (mp.count(v)) {
      cout << "Already Exist" << "\n";
    }
    mp.insert(v);
  }

  int query(int v) {
    if (mp.empty())
      return 0;
    set<int>::iterator sit;
    auto it = mp.upper_bound(v);
    if (it == mp.begin()) {
      sit = it;
    } else if (it == mp.end()) {
      sit = prev(it);
    } else {
      auto pit = prev(it);
      sit = v - *pit <= *it - v ? pit : it;
    }
    int ret = *sit;
    mp.erase(sit);
    return ret;
  }

 private:
  set<int> mp;
};

int main() {
  Tree t;
  int cnt;
  cin >> cnt;
  for (int i = 0; i < cnt; ++i) {
    int op, length;
    cin >> op >> length;
    if (op == 1) {
      t.insert(length);
    } else {
      int v = t.query(length);
      if (v == 0) {
        cout << "Empty" << "\n";
      } else {
        cout << v << "\n";
      }
    }
  }
  cout << flush;
  return 0;
}

