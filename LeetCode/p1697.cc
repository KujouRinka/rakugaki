class Solution {
 public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
    sort(edgeList.begin(), edgeList.end(), [](auto &lhs, auto &rhs) { return lhs[2] < rhs[2]; });
    vector<int> idx(queries.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&queries](int lhs, int rhs) { return queries[lhs][2] < queries[rhs][2]; });

    vector<bool> ret(queries.size());
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    int pos = 0;
    for (int i : idx) {
      while (pos < edgeList.size() && edgeList[pos][2] < queries[i][2]) {
        merge(edgeList[pos][0], edgeList[pos][1]);
        ++pos;
      }
      ret[i] = find(queries[i][0]) == find(queries[i][1]);
    }
    return ret;
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

