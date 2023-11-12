class Solution {
 public:
  string categorizeBox(int length, int width, int height, int mass) {
    this->length = length;
    this->width = width;
    this->height = height;
    this->mass = mass;
    if (isBulky() && isHeavy()) {
      return "Both";
    } else if (!isBulky() && !isHeavy()) {
      return "Neither";
    } else if (isBulky()) {
      return "Bulky";
    } else {
      return "Heavy";
    }
  }

 private:
  int length, width, height, mass;
  bool isBulky() {
    return length >= 1e4 || width >= 1e4 || height >= 1e4 || (long long) length * (long long) width * height >= 1e9;
  }

  bool isHeavy() {
    return mass >= 100;
  }
};

