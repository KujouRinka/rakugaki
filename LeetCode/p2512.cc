class Solution {
 public:
  vector<int> topStudents(
      vector<string> &positive_feedback,
      vector<string> &negative_feedback,
      vector<string> &report,
      vector<int> &student_id,
      int k
  ) {
    unordered_set<string_view> pos(positive_feedback.begin(), positive_feedback.end());
    unordered_set<string_view> neg(negative_feedback.begin(), negative_feedback.end());
    vector<pair<int, int>> v;
    for (int i = 0; i < report.size(); ++i) {
      string_view view(report[i]);
      vector<string_view> res;
      boost::split(res, view, boost::is_any_of(" "));
      auto point = accumulate(res.begin(), res.end(), 0, [&pos, &neg](auto acc, auto &view) {
        int p = 0;
        if (pos.contains(view)) {
          p = 3;
        } else if (neg.contains(view)) {
          p = -1;
        }
        return acc + p;
      });
      v.emplace_back(point, student_id[i]);
    }
    auto cmp = [](auto &pl, auto &pr) {
      return pl.first > pr.first || pl.first == pr.first && pl.second < pr.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> hp(cmp);
    int i = 0;
    for (; i < k && i < v.size(); ++i) {
      hp.push(v[i]);
    }
    for (; i < v.size(); ++i) {
      hp.push(v[i]);
      hp.pop();
    }
    vector<int> ret;
    ret.resize(k);
    int idx = k - 1;
    while (!hp.empty()) {
      ret[idx--] = hp.top().second;
      hp.pop();
    }
    return ret;
  }
};

