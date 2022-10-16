#include <iostream>
#include <string>
#include <charconv>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
  int from_base;
  cin >> from_base;
  string s;
  cin >> s;
  auto r = stoll(s, nullptr, from_base);
  int to_base;
  cin >> to_base;
  char buf[40] = {0};
  to_chars(buf, buf + 40, r, to_base);
  for_each(begin(buf), end(buf), [](char &ch) {
    ch = toupper(ch);
  });
  cout << buf << endl;
  return 0;
}

