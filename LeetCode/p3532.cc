class DSU {
public:
  DSU(int size): disjoint_set(views::iota(0) | views::take(size) | ranges::to<vector<int>>()) {
  }

  void add(int u, int v) {
    disjoint_set[find(v)] = find(u);
  }

  int find(int u) {
    if (disjoint_set[u] == u) {
      return u;
    }
    return disjoint_set[u] = find(disjoint_set[u]);
  }

  bool same(int u, int v) {
    return disjoint_set[find(u)] == disjoint_set[find(v)];
  }

private:
  vector<int> disjoint_set;
};

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries) {
    DSU d(n);
    int front = 0, back = 0;
    int cur_diff = 0;
    while (front < n) {
      while (back < n) {
        cur_diff = nums[back] - nums[front];
        if (cur_diff > maxDiff) {
          break;
        }
        d.add(front, back);
        ++back;
      }
      ++front;
    }
    return queries | std::views::transform([&d](auto &q) {
      return d.same(q[0], q[1]);
    }) | std::ranges::to<vector<bool>>();
  }
};

