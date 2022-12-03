class Solution {
 public:
  int numSimilarGroups(vector<string>& strs) {
    f.reserve(strs.size());
    for (int i = 0; i < strs.size(); ++i)
      f.push_back(i);
    for (int i = 0; i < strs.size(); ++i) {
      for (int j = i + 1; j < strs.size(); ++j) {
        if (similar(strs[i], strs[j]))
          Union(i, j);
      }
    }
    unordered_set<int> st;
    for (int i : f)
      st.insert(find(i));
    return st.size();
  }

 private:
  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  void Union(int x, int y) {
    f[find(x)] = f[find(y)];
  }

  bool similar(const string &s1, const string &s2) {
    if (s1.size() != s2.size())
      return false;
    int diff = 0;
    int diff_memo = 0;
    for (int i = 0; i < s1.size(); ++i) {
      char c1 = s1[i], c2 = s2[i];
      if (c1 != c2) {
        if (++diff > 2)
          return false;
        diff_memo ^= (c1 ^ c2);
      }
    }
    return diff_memo == 0;
  }

  vector<int> f;
};

