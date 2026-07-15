class TreeAncestor {
public:
  TreeAncestor(int n, vector<int> &parent) {
    int m = bit_width(static_cast<unsigned>(n));
    pp.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      pp[i][0] = parent[i];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pp[j][i - 1] == -1) {
          pp[j][i] = -1;
          continue;
        }
        pp[j][i] = pp[pp[j][i - 1]][i - 1];
      }
    }
  }

  int getKthAncestor(int node, int k) {
    int m = bit_width(static_cast<unsigned int>(k));
    for (int i = 0; i < m; ++i) {
      if ((1 << i & k) == 0) {
        continue;
      }
      node = pp[node][i];
      if (node == -1) {
        break;
      }
    }

    return node;
  }

private:
  vector<vector<int>> pp;
};

