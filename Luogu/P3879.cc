#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, vector<int>> memo;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int m;
    cin >> m;
    string s;
    while (m--) {
      cin >> s;
      if (memo[s].empty() || memo[s].back() != i)
        memo[s].push_back(i);
    }
  }
  cin >> n;
  string s;
  while (n--) {
    cin >> s;
    for (int i : memo[s])
      cout << i << " ";
    cout << "\n";
  }
  cout << flush;
  return 0;
}

