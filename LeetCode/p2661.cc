class Solution {
 public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    struct Memo {
      int id0, id1;
      Memo() = default;
      Memo(int z, int o) : id0(z), id1(o) {}
    };
    int id0sz = mat.size();
    int id1sz = mat[0].size();
    vector<int> col_cnt(id1sz, 0);
    vector<int> row_cnt(id0sz, 0);
    unordered_map<int, Memo> g;
    g.reserve(id0sz * id1sz);
    for (int id0 = 0; id0 < id0sz; ++id0) {
      for (int id1 = 0; id1 < id1sz; ++id1) {
        g.insert({mat[id0][id1], Memo(id0, id1)});
      }
    }
    for (int i = 0; i < arr.size(); ++i) {
      auto memo_it = g.find(arr[i]);
      auto i0 = memo_it->second.id0;
      auto i1 = memo_it->second.id1;
      if (++col_cnt[i1] == id0sz || ++row_cnt[i0] == id1sz) {
        return i;
      }
    }
    return -1;
  }
};

