#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
  int cnt;
  cin >> cnt;
  vector<int> memo;
  memo.reserve(cnt);
  while (cnt--) {
	int v;
	cin >> v;
	memo.push_back(v);
  }
  sort(memo.begin(), memo.end());
  long long ret = 1;
  int to_minus = 0;
  for (auto i : memo) {
	ret = ret * (i - to_minus) % MOD;
	++to_minus;
  }
  cout << ret << endl;
  return 0;
}

