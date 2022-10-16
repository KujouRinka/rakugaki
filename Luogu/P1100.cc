#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  uint32_t ut;
  cin >> ut;
  cout << ((ut & 0xffff0000) >> 16) + ((ut & 0xffff) << 16) << endl;
  return 0;
}

