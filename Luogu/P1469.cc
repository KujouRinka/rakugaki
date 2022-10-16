#include <iostream>

using namespace std;

int main() {
  int cnt;
  cin >> cnt;
  int ret = 0;
  while (cnt--) {
    int input;
	cin >> input;
	ret ^= input;
  }
  cout << ret << endl;
  return 0;
}

