class Solution {
  enum CLASS {
    ID = 0, RATING, VEGAN_FRIENDLY, PRICE, DISTANCE,
  };
 public:
  vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<int> ret;
    bool vf = veganFriendly;
    auto it = partition(restaurants.begin(), restaurants.end(), [veganFriendly, maxPrice, maxDistance](auto &v) {
      return (!veganFriendly || v[VEGAN_FRIENDLY]) && v[PRICE] <= maxPrice && v[DISTANCE] <= maxDistance;
    });
    sort(restaurants.begin(), it, [](auto &lhs, auto &rhs) {
      return std::pair(lhs[RATING], lhs[ID]) > std::pair(rhs[RATING], rhs[ID]);
    });
    transform(restaurants.begin(), it, back_inserter(ret), [](auto &v) {
      return v[ID];
    });
    return ret;
  }
};

