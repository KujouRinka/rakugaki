#include <iostream>

using namespace std;

template<typename T>
int find(T &mp, int x) {
  if (mp[x] == x)
    return x;
  return mp[x] = find(mp, mp[x]);
}

template<typename T>
void add(T &mp, int x, int y) {
  mp[find(mp, x)] = mp[find(mp, y)];
}

int main() {
  int lower, upper, prime;
  cin >> lower >> upper >> prime;
  int ret = upper - lower + 1;
  // unordered_map<int, int> mp;
  // mp.reserve(ret);
  int mp[100505] = {0};
  bool prime_mark[100505] = {0};
  // vector<bool> prime_mark(upper + 1);
  for (int i = lower; i <= upper; ++i)
    mp[i] = i;
  for (int i = 2; i <= upper; ++i) {
    if (prime_mark[i])
      continue;
    prime_mark[i] = true;
    for (int j = i * 2; j <= upper; j += i) {
      // if (prime_mark[j])
      //   continue;
      prime_mark[j] = true;
      if (i < prime)
        continue;
      if (j - i >= lower && find(mp, j - i) != find(mp, j)) {
        add(mp, j - i, j);
        --ret;
      }
    }
  }
  cout << ret << endl;
  return 0;
}

