using namespace std;
class MagicDictionary {
 public:
  MagicDictionary() = default;

  void buildDict(const vector<string> &dictionary) {
    for_each(dictionary.begin(), dictionary.end(), [this](auto &s) {
      _trie.insert(s);
    });
  }

  bool search(const string &searchWord) {
    return _trie.search(searchWord, _trie.head);
  }

 private:
  class Trie {
   public:
    struct Node {
      Node() : word(false) {}
      bool word;
      array<Node *, 26> children{};
    };
    Node *head;
    Trie() : head(new Node) {}
    ~Trie() { /* define destructor here */ }
    void insert(const string &s) {
      auto *cur = head;
      for (char ch : s) {
        if (!cur->children[ch - 'a'])
          cur->children[ch - 'a'] = new Node;
        cur = cur->children[ch - 'a'];
      }
      cur->word = true;
    }

    bool search(const string &s, Node *node, bool diff = false, int idx = 0) {
      if (idx == s.size() && node->word && diff)
        return true;
      for (int i = 0; i < 26; ++i) {
        if (!node->children[i])
          continue;
        if (diff && i + 'a' != s[idx])
          continue;
        if (search(s, node->children[i], i + 'a' != s[idx] || diff, idx + 1))
          return true;
      }
      return false;
    }
  };

  Trie _trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

