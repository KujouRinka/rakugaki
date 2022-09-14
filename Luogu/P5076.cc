#include <iostream>
#include <map>
#include <numeric>

using namespace std;

class Bin {
 public:
  Bin() {
    ito_contains.insert({-2147483647, 0});
    ito_contains.insert({2147483647, 0});
  };

  int rankOf(int x) {
    return accumulate(ito_contains.begin(), ito_contains.lower_bound(x), 0, [](int acc, auto rhs) -> int {
      return acc + rhs.second;
    }) + 1;
  }

  int withRank(int r) {
    int sum = 0;
    int ret = 0;
    for (auto &it : ito_contains) {
      sum += it.second;
      // ++ret;
      if (sum >= r) {
        ret = it.first;
        break;
      }
    }
    return ret;
  }

  int prevOf(int x) {
    return prev(ito_contains.lower_bound(x))->first;
  }

  int nextOf(int x) {
    return ito_contains.upper_bound(x)->first;
  }

  void insert(int x) {
    ++ito_contains[x];
  }

 private:
  map<int, int> ito_contains;
};

int main() {
  Bin b;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int op, x;
    cin >> op >> x;
    switch (op) {
      case 1:
        cout << b.rankOf(x) << "\n";
        break;
      case 2:
        cout << b.withRank(x) << "\n";
        break;
      case 3:
        cout << b.prevOf(x) << "\n";
        break;
      case 4:
        cout << b.nextOf(x) << "\n";
        break;
      case 5:
        b.insert(x);
        break;
    }
  }
  cout << flush;
  return 0;
}

