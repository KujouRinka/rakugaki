class Solution {
 public:
  vector<int> decrypt(vector<int> &code, int k) {
    if (k == 0) {
      return vector<int>(code.size(), 0);
    }
    vector<int> ret(code.size());
    if (k > 0) {
      helper(code.begin(), code.end(), k, ret.begin());
    } else {
      helper(code.rbegin(), code.rend(), -k, ret.rbegin());
    }
    return ret;
  }

 private:
  template<typename ForwardIter, typename InsertIter>
  void helper(ForwardIter begin, ForwardIter end, int k, InsertIter iter) {
    auto len = end - begin;
    int s = 0;
    for (int i = 1; i <= k; ++i) {
      s += begin[i % len];
    }
    vector<int> ret(len);

    for (int i = 0; i < len; ++i) {
      *iter++ = s;
      s -= *(begin + (i + 1) % len);
      s += *(begin + (i + k + 1) % len);
    }
  }
};

