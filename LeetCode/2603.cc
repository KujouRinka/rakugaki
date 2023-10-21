class Solution {
 public:
  int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
    auto n = coins.size();
    vector<vector<int>> g(n);
    vector<int> degree(n);
    for_each(edges.begin(), edges.end(), [&](auto &v) {
      auto a = v[0], b = v[1];
      g[a].push_back(b);
      g[b].push_back(a);
      ++degree[a];
      ++degree[b];
    });

    queue<int> leaves;
    queue<int> endpoint;
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) {
        if (coins[i] == 1) {
          endpoint.push(i);
        } else {
          leaves.push(i);
        }
      }
    }

    while (!leaves.empty()) {
      int lf = leaves.front();
      leaves.pop();
      --n;
      --degree[lf];
      for_each(g[lf].begin(), g[lf].end(), [&](int i) {
        if (--degree[i] == 1) {
          if (coins[i] == 1) {
            endpoint.push(i);
          } else {
            leaves.push(i);
          }
        }
      });
    }

    for (int i = 0; i < 2; ++i) {
      for (auto sz = endpoint.size(); sz > 0; --sz) {
        int lf = endpoint.front();
        endpoint.pop();
        --n;
        --degree[lf];
        for_each(g[lf].begin(), g[lf].end(), [&](int i) {
          if (--degree[i] == 1) {
            endpoint.push(i);
          }
        });
      }
    }

    return max<int>(0, n - 1) * 2;
  }
};

