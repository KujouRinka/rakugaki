class Solution {
 public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    vector<long long> left(maxHeights.size());
    helper(maxHeights.begin(), maxHeights.end(), left.begin());
    vector<long long> right(maxHeights.size());
    helper(maxHeights.rbegin(), maxHeights.rend(), right.rbegin());

    long long ret = 0;
    for (int i = 0; i < maxHeights.size(); ++i) {
      ret = max(ret, left[i] + right[i] - maxHeights[i]);
    }
    return ret;
  }

 private:
  template<typename ForwardIter, typename OutputIter>
  void helper(ForwardIter begin, ForwardIter end, OutputIter output) {
    auto o = output;
    stack<ForwardIter> incr_st;
    for (auto it = begin; it != end; ++it, ++output) {
      while (!incr_st.empty() && *incr_st.top() > *it) {
        incr_st.pop();
      }
      if (incr_st.empty()) {
        *output = *it * (distance(begin, it) + 1);
      } else {
        *output = *it * (distance(incr_st.top(), it)) + *(o + distance(begin, incr_st.top()));
      }
      incr_st.push(it);
    }
  }
};

