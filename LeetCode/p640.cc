class Solution {
 public:
  string solveEquation(string equation) {
    int lx = 0, lv = 0;
    int rx = 0, rv = 0;
    bool left = true;
    int front = 0, back = isalpha(equation[0]) || equation[0] == 'x' ? 0 : 1;
    while (front < equation.size()) {
      while (back < equation.size() && equation[back] != '+' && equation[back] != '-' && equation[back] != '=')
        ++back;
      int fac;
      int sign = 1;
      while (equation[front] == '+' || equation[front] == '-' || equation[front] == '=') {
        if (equation[front] == '-')
          sign = -1;
        ++front;
      }
      if (front < back) {
        if (back - front == 1 && equation[front] == 'x') {
          fac = sign;
        } else {
          from_chars(equation.c_str() + front, equation.c_str() + back, fac);
          fac *= sign;
        }
        bool has_x = equation[back - 1] == 'x';
        (left ? (has_x ? lx : lv) : (has_x ? rx : rv)) += fac;
        if (left && equation[back] == '=')
          left = false;
      }
      front = back++;
    }
    lx -= rx;
    lv -= rv;
    if (lx == 0) {
      if (lv == 0)
        return "Infinite solutions";
      return "No solution";
    }
    return "x=" + to_string(-lv / lx);
  }
};
   
