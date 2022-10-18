#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
bitset<100000001> bs;

int main() {
  std::ios::sync_with_stdio(false);
  int range, cnt;
  cin >> range >> cnt;
  bs.flip();
  int cur_primer = 2;
  while (cur_primer < range) {
    int ptr = cur_primer * 2;
    for (; ptr <= range; ptr += cur_primer)
      bs.reset(ptr);
    while (++cur_primer < range && !bs[cur_primer]) {}
  }
  vector<int> memo;
  memo.reserve(range / 1000);
  for (int i = 2; i <= range; ++i) {
    if (bs[i])
      memo.push_back(i);
  }
  for (int i = 0; i < cnt; ++i) {
    int query;
    cin >> query;
    cout << memo[query - 1] << endl;
  }
  return 0;
}

