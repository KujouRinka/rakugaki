class Solution {
public:
  vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries) {
    vector idx = views::iota(0) | views::take(n) | ranges::to<vector>();
    ranges::sort(idx, {}, [&nums](int i) { return nums[i]; });

    vector<int> num_to_idx(n);
    ranges::for_each(views::zip(views::iota(0), idx), [&num_to_idx](auto &&t) {
      num_to_idx[get<1>(t)] = get<0>(t);
    });

    int m = bit_width(static_cast<unsigned>(n));
    // jmp[num][2^step] = idx
    int right = 0;
    vector<vector<int>> jmp(n, vector<int>(m, -1));
    for (int left = 0; left < n; ++left) {
      right = max(right, left);
      while (right + 1 < n && nums[idx[right + 1]] - nums[idx[left]] <= maxDiff) {
        ++right;
      }

      jmp[left][0] = right;
    }

    for (int step = 1; step < m; ++step) {
      for (int i = 0; i < n; ++i) {
        int t = jmp[i][step - 1];
        if (t == -1) {
          continue;
        }
        jmp[i][step] = jmp[t][step - 1];
      }
    }

    vector<int> ret;
    for (auto &q: queries) {
      int l = min(num_to_idx[q[0]], num_to_idx[q[1]]);
      int r = max(num_to_idx[q[0]], num_to_idx[q[1]]);
      if (l == r) {
        ret.push_back(0);
        continue;
      }

      int p = 0;
      for (int i = m - 1; i >= 0; --i) {
        if (jmp[l][i] < r) {
          p |= 1 << i;
          l = jmp[l][i];
        }
      }
      ret.push_back(jmp[l][0] >= r ? p + 1 : -1);
    }

    return ret;
  }
};

