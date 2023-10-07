class Solution {
 public:
  vector<bool> checkIfPrerequisite(
      int numCourses,
      vector<vector<int>> &prerequisites,
      vector<vector<int>> &queries
  ) {
    auto p = accumulate(
        prerequisites.begin(), prerequisites.end(),
        make_pair(vector<int>(numCourses, 0), vector<vector<int>>(numCourses)),
        [](auto acc, auto &p) {
          ++acc.first[p[1]];
          acc.second[p[0]].push_back(p[1]);
          return std::move(acc);
        }
    );
    auto in_cnt = std::move(p.first);
    auto from_to = std::move(p.second);

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in_cnt[i] == 0) {
        q.push(i);
      }
    }
    vector<int> ret;
    vector<vector<bool>> memo(numCourses, vector<bool>(numCourses, false));
    while (!q.empty()) {
      auto cur_course = q.front();
      q.pop();
      for (auto &next_course : from_to[cur_course]) {
        memo[cur_course][next_course] = true;
        for (int i = 0; i < numCourses; ++i) {
          memo[i][next_course] = memo[i][next_course] || memo[i][cur_course];
        }
        if (--in_cnt[next_course] == 0) {
          q.push(next_course);
        }
      }
    }

    return accumulate(queries.begin(), queries.end(), vector<bool>(), [&memo](auto acc, auto &q) {
      acc.push_back(memo[q[0]][q[1]]);
      return std::move(acc);
    });
  }
};

