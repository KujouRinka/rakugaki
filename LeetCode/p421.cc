class BinTrie {
 public:
  BinTrie() : root(new node) {};

  void insert(int i) {
    auto *cur = root;
    for (int j = 30; j >= 0; --j) {
      int mov = 1 << j;
      if (!(i & mov)) {
        if (!cur->zero)
          cur->zero = new node;
        cur = cur->zero;
      } else {
        if (!cur->one)
          cur->one = new node;
        cur = cur->one;
      }
    }
  }

  int maxXorOf(int i) {
    auto *cur = root;
    int ret = 0;
    for (int j = 30; j >= 0; --j) {
      int mov = 1 << j;
      if (i & mov) {    // I'm 1
        if (cur->zero) {
          ret |= mov;
          cur = cur->zero;
        } else {
          cur = cur->one;
        }
      } else {    // I'm 0
        if (cur->one) {
          ret |= mov;
          cur = cur->one;
        } else {
          cur = cur->zero;
        }
      }
    }
    return ret;
  }

 private:
  struct node {
    node() : zero(nullptr), one(nullptr) {};
    node *zero;
    node *one;
  };

  node *root;
};

class Solution {
 public:
  int findMaximumXOR(const vector<int> &nums) {
    BinTrie t;
    for_each(nums.begin(), nums.end(), [&t](int i) {
      t.insert(i);
    });
    int m = 0;
    for_each(nums.begin(), nums.end(), [&m, &t](int i) {
      m = max(m, t.maxXorOf(i));
    });
    return m;
  }
};

