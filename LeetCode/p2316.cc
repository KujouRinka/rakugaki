class Solution {
 public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    f.resize(n);
    sz.resize(n, 1);
    iota(f.begin(), f.end(), 0);
    for (auto &e : edges) {
      insert(e[0], e[1]);
    }
    long long ret = 0;
    for (int i = 0; i < n; ++i) {
      ret += n - sz[find(i)];
    }
    return ret / 2;
  }

 private:
  vector<int> f;
  vector<int> sz;

  void insert(int p, int x) {
    int rx = find(p);
    int ry = find(x);
    if (rx != ry) {
      if (sz[rx] > sz[ry]) {
        f[ry] = rx;
        sz[rx] += sz[ry];
      } else {
        f[rx] = ry;
        sz[ry] += sz[rx];
      }
    }
  }

  int find(int x) {
    if (f[x] == x) {
      return x;
    }
    return f[x] = find(f[x]);
  }
};

