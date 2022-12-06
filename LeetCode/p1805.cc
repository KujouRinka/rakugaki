class Solution {
 public:
  int numDifferentIntegers(const string &word) {
    unordered_set<string> st;
    auto start = 0;
    while (start < word.size()) {
      while (start < word.size() && !isdigit(word[start]))
        ++start;
      auto end = start;
      while (end < word.size() && isdigit(word[end]))
        ++end;
      if (start == end)
        break;
      while (start < end && word[start] == '0')
        ++start;
      if (start == end)
        st.insert("0");
      else
        st.insert(word.substr(start, end - start));
      start = end;
    }
    return st.size();
  }
};

