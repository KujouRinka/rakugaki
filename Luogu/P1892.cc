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
  int person, rs;
  cin >> person >> rs;
  int relation[1001] = {0};
  for (int i = 1; i <= person; ++i)
    relation[i] = i;
  int enemy[1001] = {0};
  while (rs--) {
    char r;
    int x, y;
    cin >> r >> x >> y;
    if (r == 'E') {
      if (enemy[x]) {
        add(relation, enemy[x], y);
      } else {
        enemy[x] = y;
      }
      if (enemy[y]) {
        add(relation, enemy[y], x);
      } else {
        enemy[y] = x;
      }
    } else {
      add(relation, x, y);
    }
  }
  int s[1001] = {0};
  int cnt = 0;
  for (int i = 1; i <= person; ++i) {
    if (++s[find(relation, i)] == 1)
      ++cnt;
  }
  cout << cnt << endl;
  return 0;
}

