class Solution {
 public:
  int calPoints(vector<string> &operations) {
    int ret = 0;
    vector<int> st;

    for (const auto &op : operations) {
      if (op == "+") {
        int bs = *(st.end() - 1) + *(st.end() - 2);
        ret += bs;
        st.push_back(bs);
      } else if (op == "D") {
        st.push_back(st.back() * 2);
        ret += st.back();
      } else if (op == "C") {
        ret -= st.back();
        st.pop_back();
      } else {
        st.push_back(stoi(op));
        ret += st.back();
      }
    }
    return ret;
  }
};

