class PathTrie {
 public:
  PathTrie() : root(new Node(false)) {};

  void add(const string &path) {
    int f = 0;
    int b = 1;
    string to_add;
    auto p = root;
    while (f < path.size()) {
      to_add.clear();
      while (b < path.size() && path[b] != '/')
        to_add.push_back(path[b++]);
      if (p->ne.count(to_add) == 0)
        p->ne[to_add] = make_shared<Node>(false);
      p = p->ne[to_add];
      f = b++;
    }
    p->end = true;
  }

  vector<string> get() {
    vector<string> ret;
    string s;
    helper(ret, root, s);
    return ret;
  }

 private:
  struct Node {
    Node(bool b) : end(b) {}
    bool end;
    unordered_map<string, shared_ptr<Node>> ne;
  };
  shared_ptr<Node> root;

  void helper(vector<string> &v, const shared_ptr<Node>& node, string &s) {
    if (node == nullptr || node->end) {
      v.push_back(s);
      return;
    }
    for (auto &p : node->ne) {
      string to_append = "/" + p.first;
      s.append(to_append);
      helper(v, p.second, s);
      s.resize(s.size() - to_append.size());
    }
  }
};

class Solution {
 public:
  vector<string> removeSubfolders(vector<string> &folder) {
    PathTrie trie;
    for_each(folder.begin(), folder.end(), [&trie](auto &s) {
      trie.add(s);
    });
    return trie.get();
  }
};

