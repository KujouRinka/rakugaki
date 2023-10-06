class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    auto p = accumulate(
        prerequisites.begin(), prerequisites.end(),
        make_pair(vector<int>(numCourses, 0), vector<vector<int>>(numCourses)),
        [](auto acc, auto &p) {
          ++acc.first[p[0]];
          acc.second[p[1]].push_back(p[0]);
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
    vector<int> learned(numCourses, 0);
    while (!q.empty()) {
      for (auto i = q.size(); i > 0; --i) {
        auto course = q.front();
        q.pop();
        learned[course] = 1;
        for_each(from_to[course].begin(), from_to[course].end(), [&in_cnt, &q](auto next_course) {
          if (--in_cnt[next_course] == 0) {
            q.push(next_course);
          }
        });
      }
    }

    return ranges::all_of(learned, [](auto i) {
      return i != 0;
    });
  }
};

