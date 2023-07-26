using ll = long long;

class SegmentTree {
 public:
  inline void push_down(ll index) {
    st[index << 1].lazy ^= 1;
    st[index << 1 | 1].lazy ^= 1;
    st[index << 1].s = st[index << 1].tr - st[index << 1].tl + 1 - st[index << 1].s;
    st[index << 1 | 1].s = st[index << 1 | 1].tr - st[index << 1 | 1].tl + 1 - st[index << 1 | 1].s;
    st[index].lazy = 0;
  }

  inline void push_up(ll index) {
    st[index].s = st[index << 1].s + st[index << 1 | 1].s;
  }

  SegmentTree(vector<int> &init_list) {
    st = vector<SegmentTreeNode>(init_list.size() * 4 + 10);
    build(init_list, 1, init_list.size());
  }

  void build(vector<int> &init_list, ll l, ll r, ll index = 1) {
    st[index].tl = l;
    st[index].tr = r;
    st[index].lazy = 0;
    if (l == r) {
      st[index].s = init_list[l - 1];
    } else {
      ll mid = (l + r) >> 1;
      build(init_list, l, mid, index << 1);
      build(init_list, mid + 1, r, index << 1 | 1);
      push_up(index);
    }
  }

  void flip(ll l, ll r, ll index = 1) {
    if (l > st[index].tr or r < st[index].tl)
      return;
    else if (l <= st[index].tl and st[index].tr <= r) {
      st[index].s = st[index].tr - st[index].tl + 1 - st[index].s;
      st[index].lazy ^= 1;
    } else {
      if (st[index].lazy)
        push_down(index);
      flip(l, r, index << 1);
      flip(l, r, index << 1 | 1);
      push_up(index);
    }
  }

  ll query(ll l, ll r, ll index = 1) {
    if (l <= st[index].tl and st[index].tr <= r) {
      return st[index].s;
    } else {
      if (st[index].lazy)
        push_down(index);
      if (r <= st[index << 1].tr)
        return query(l, r, index << 1);
      else if (l > st[index << 1].tr)
        return query(l, r, index << 1 | 1);
      return query(l, r, index << 1) + query(l, r, index << 1 | 1);
    }
  }

 private:
  struct SegmentTreeNode {
    ll tl;
    ll tr;
    ll s;
    int lazy;
  };
  vector<SegmentTreeNode> st;
};

class Solution {
 public:
  vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
    vector<ll> res;
    SegmentTree tree(nums1);
    ll s = accumulate(nums2.begin(), nums2.end(), 0LL);
    for (int i = 0; i < queries.size(); i++) {
      auto &qi = queries[i];
      if (qi[0] == 1)
        tree.flip(qi[1] + 1, qi[2] + 1);
      else if (qi[0] == 2)
        s += tree.query(1, nums1.size()) * qi[1];
      else
        res.push_back(s);
    }
    return res;
  }
};

