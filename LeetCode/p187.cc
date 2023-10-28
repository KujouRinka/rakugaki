class Solution {
  using ll = long long;
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() < 10) {
      return {};
    }
    unordered_map<char, int> p = {
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'T', 3},
    };
    ll cur_hash = 0;
    unordered_map<ll, int> st;
    size_t idx = 0;
    for (; idx < 10; ++idx) {
      cur_hash *= 4;
      cur_hash += p[s[idx]];
    }
    st.insert({cur_hash, 1});

    ll po = pow(4, 9);
    vector<string> ret;
    for (; idx < s.size(); ++idx) {
      cur_hash -= po * p[s[idx - 10]];
      cur_hash *= 4;
      cur_hash += p[s[idx]];
      if (st[cur_hash]++ == 1) {
        ret.push_back(s.substr(idx - 9, 10));
      }
    }
    return ret;
  }
};

