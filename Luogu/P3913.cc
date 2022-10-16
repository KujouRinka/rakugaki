#include <iostream>
#include <unordered_set>

using namespace std;

using ll = long long;

int main() {
  unordered_set<ll> v;
  unordered_set<ll> h;
  v.reserve(1000000);
  h.reserve(1000000);
  int N, cnt;
  scanf("%d%d", &N, &cnt);
  while (cnt--) {
        ll r, c;
        scanf("%lld%lld", &r, &c);
        v.insert(r);
        h.insert(c);
  }
  cout << (v.size() + h.size()) * N - v.size() * h.size() << endl;
  return 0;
}

