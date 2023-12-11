struct UF {
  vector<int> f;

  UF(int sz) : f(sz) {
    iota(f.begin(), f.end(), 0);
  }

  int find(int x) {
    if (f[x] == x) {
      return x;
    }
    return f[x] = find(f[x]);
  }

  void unite(int x, int y) {
    f[find(x)] = find(y);
  }

  bool connected(int x, int y) {
    return find(x) == find(y);
  }
};

class Solution {
  struct Edge {
    int b0, b1, w;
    Edge(int x, int y, int z) : b0(x), b1(y), w(z) {}
    bool operator<(const Edge &rhs) const {
      return w < rhs.w;
    }
  };
 public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int id0sz = heights.size();
    int id1sz = heights[0].size();
    UF uf(id0sz * id1sz);
    auto pos_to_id = [id0sz, id1sz](int x, int y) {
      return x * id1sz + y;
    };
    vector<Edge> edges;
    edges.reserve(id0sz * id1sz * 2);
    for (int i0 = 0; i0 < id0sz; ++i0) {
      for (int i1 = 0; i1 < id1sz; ++i1) {
        auto block_id = pos_to_id(i0, i1);
        if (i0 > 0) {
          edges.emplace_back(block_id - id1sz, block_id, abs(heights[i0][i1] - heights[i0 - 1][i1]));
        }
        if (i1 > 0) {
          edges.emplace_back(block_id - 1, block_id, abs(heights[i0][i1] - heights[i0][i1 - 1]));
        }
      }
    }
    edges.shrink_to_fit();

    sort(edges.begin(), edges.end());
    for (auto &e : edges) {
      uf.unite(e.b0, e.b1);
      if (uf.connected(0, id0sz * id1sz - 1)) {
        return e.w;
      }
    }
    return 0;
  }
};

