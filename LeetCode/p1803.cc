class BinTrie {
 public:
  BinTrie() : root(new node) {};
  ~BinTrie() {
    // do memory free job
  }

  void add(int x) {
    int bit_mask = 1 << 14;
    auto *cur = root;
    for (; bit_mask > 0; bit_mask >>= 1) {
      ++cur->child_cnt;
      if (x & bit_mask) {
        // add to right
        if (cur->one == nullptr)
          cur->one = new node;
        cur = cur->one;
      } else {
        // add to left
        if (cur->zero == nullptr)
          cur->zero = new node;
        cur = cur->zero;
      }
    }
    ++cur->child_cnt;
  }

  int f(int upper, int x) {
    int ret = 0;
    int bit_mask = 1 << 14;
    auto *cur = root;
    for (; bit_mask > 0 && cur != nullptr; bit_mask >>= 1) {
      int upper_bit = upper & bit_mask, x_bit = x & bit_mask;
      if (upper_bit) {
        // could choose zero or one path
        if (x_bit) {
          ret += cur->one ? cur->one->child_cnt : 0;
          cur = cur->zero;
        } else {
          ret += cur->zero ? cur->zero->child_cnt : 0;
          cur = cur->one;
        }
      } else {
        // no choose
        if (x_bit) {
          // x_bit: 1, choose other as 0
          cur = cur->one;
        } else {
          // x_bit: 0, choose other as 1
          cur = cur->zero;
        }
      }
    }
    return ret;
  }

 private:
  struct node {
    node() : child_cnt(0), zero(nullptr), one(nullptr) {};
    int child_cnt;
    node *zero;
    node *one;
  };

  node *root;
};

class Solution {
 public:
  int countPairs(const vector<int> &nums, int low, int high) {
    BinTrie trie;
    for_each(nums.begin(), nums.end(), [&trie](int x) {
      trie.add(x);
    });
    int ret = 0;
    for_each(nums.begin(), nums.end(), [this, &trie, &ret, low, high](int x) {
      ret += f(trie, high + 1, x) - f(trie, low, x);
    });
    return ret >> 1;
  }

 private:
  int f(BinTrie &trie, int upper, int x) {
    return trie.f(upper, x);
  }
};

