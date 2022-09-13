#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
  string input;
  cin >> input;
  vector<bool> matched(input.size(), false);
  stack<size_t> r_b;
  stack<size_t> s_b;
  for (size_t i = 0; i < input.size(); ++i) {
    switch (input[i]) {
      case '(':
        r_b.push(i);
        break;
      case '[':
        s_b.push(i);
        break;
      case ')':
        if (r_b.empty() || (!s_b.empty() && r_b.top() < s_b.top()))
          continue;
        matched[i] = true;
        matched[r_b.top()] = true;
        r_b.pop();
        break;
      case ']':
        if (s_b.empty() || (!r_b.empty() && s_b.top() < r_b.top()))
          continue;
        matched[i] = true;
        matched[s_b.top()] = true;
        s_b.pop();
        break;
    }
  }
  string ret;
  ret.reserve(input.size());
  for (size_t i = 0; i < input.size(); ++i) {
    char ch = input[i];
    if (matched[i]) {
      ret.push_back(ch);
    } else if (ch == '(' || ch == ')') {
      ret.append("()");
    } else if (ch == '[' || ch == ']') {
      ret.append("[]");
    }
  }
  cout << ret << endl;
  return 0;
}

