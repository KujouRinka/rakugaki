class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (tomatoSlices & 1) {
      return {};
    }
    int x = tomatoSlices / 2 - cheeseSlices;
    int y = cheeseSlices * 2 - tomatoSlices / 2;
    if (x < 0 || y < 0) {
      return {};
    }
    return {x, y};
  }
};

