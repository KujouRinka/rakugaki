class Solution {
 public:
  bool squareIsWhite(const string &coordinates) {
    return (coordinates[0] - 'a' + coordinates[1] - '1') & 1;
  }
};

