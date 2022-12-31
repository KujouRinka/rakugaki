class Solution {
 public:
  string largestMerge(string_view word1, string_view word2) {
    int p1 = 0, p2 = 0;
    string merge;
    merge.reserve(word1.size() + word2.size());
    while (p1 < word1.size() && p2 < word2.size()) {
      if (word1.substr(p1) > word2.substr(p2)) {
        merge.push_back(word1[p1++]);
      } else {
        merge.push_back(word2[p2++]);
      }
    }
    merge.append(word1.substr(p1));
    merge.append(word2.substr(p2));
    return merge;
  }
};

