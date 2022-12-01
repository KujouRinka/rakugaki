class Fliper {
 public:
  Fliper(char init, char second) : now(init), to_switch(second) {}

  bool operator==(char ch) { return now == ch; }
  bool operator!=(char ch) { return now != ch; }

  void Switch() { swap(now, to_switch); }

 private:
  char now, to_switch;
};

class Solution {
 public:
  int minOperations(const string &s) {
    int fflip = 0, sflip = 0;
    Fliper ff('0', '1'), sf('1', '0');
    for (char ch : s) {
      if (ff != ch) ++fflip;
      if (sf != ch) ++sflip;
      ff.Switch();
      sf.Switch();
    }
    return min(fflip, sflip);
  }
};

