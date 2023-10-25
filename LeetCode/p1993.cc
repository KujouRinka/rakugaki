class LockingTree {
 public:
  LockingTree(vector<int> &parent)
      : ch_to_p(parent), p_to_ch(parent.size()), locked(parent.size(), -1) {
    for (int i = 1; i < parent.size(); ++i) {
      p_to_ch[parent[i]].push_back(i);
    }
  }

  bool lock(int num, int user) {
    if (locked[num] != -1) {
      return false;
    }
    locked[num] = user;
    return true;
  }

  bool unlock(int num, int user) {
    if (locked[num] != user) {
      return false;
    }
    locked[num] = -1;
    return true;
  }

  bool upgrade(int num, int user) {
    if (locked[num] != -1) {
      return false;
    }
    if (!check_parents(num)) {
      return false;
    }
    if (!unlock_children(num)) {
      return false;
    }
    locked[num] = user;
    return true;
  }

 private:
  vector<int> ch_to_p;
  vector<vector<int>> p_to_ch;
  vector<int> locked;

  bool unlock_children(int num) {
    if (p_to_ch[num].empty()) {
      return false;
    }
    bool ret = false;
    for (auto ch : p_to_ch[num]) {
      if (locked[ch] != -1) {
        ret = true;
        locked[ch] = -1;
      }
      if (unlock_children(ch)) {
        ret = true;
      }
    }
    return ret;
  }

  bool check_parents(int num) {
    while (ch_to_p[num] != -1) {
      auto p = ch_to_p[num];
      if (locked[p] != -1) {
        return false;
      }
      num = p;
    }
    return true;
  }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

