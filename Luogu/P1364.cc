#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int ret;
  Solution(int n) : n(n), ret(0x7fffffff) {
    f.reserve(n);
    sz.reserve(n);
    val.reserve(n);
  }

  void run() {
    for (int i = 1; i <= n; ++i) {
      int w, u, v;
      cin >> w >> u >> v;
      val[i] = {w, u, v};
    }
    init(1, 0, f[1]);
    fillF(1);
  }

  int init(int id, int depth, int &f1) {
    if (id == 0)
      return 0;
    int sum = val[id][0];
    f1 += depth * val[id][0];
    sum += init(val[id][1], depth + 1, f1);
    sum += init(val[id][2], depth + 1, f1);
    sz[id] = sum;
    return sum;
  }

  void fillF(int id) {
    ret = min(f[id], ret);
    int left = val[id][1], right = val[id][2];
    if (left) {
      f[left] = f[id] + sz[1] - sz[left] - sz[left];
      fillF(left);
    }
    if (right) {
      f[right] = f[id] + sz[1] - sz[right] - sz[right];
      fillF(right);
    }
  }

 private:
  int n;
  unordered_map<int, int> f;
  unordered_map<int, int> sz;
  unordered_map<int, vector<int>> val;
};

int main() {
  int n;
  cin >> n;
  auto s = Solution(n);
  s.run();
  cout << s.ret << endl;
  return 0;
}

