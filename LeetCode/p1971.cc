class Solution {
 public:
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    for (auto &edge : edges)
      merge(edge[0], edge[1]);
    return find(source) == find(destination);
  }

 private:
  vector<int> f;
  
  void merge(int x, int y) {
    f[find(x)] = f[find(y)];
  }
  
  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }
};

