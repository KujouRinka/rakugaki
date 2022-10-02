#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  Solution() = default;

  void run() {
    int max_time = 0;
    int n;
    cin >> n;
    vector<int> memo(n + 1);
    while (n--) {
      int no, time;
      cin >> no >> time;
      int this_time = 0;
      while (true) {
        int pre;
        if (cin >> pre && pre == 0)
          break;
        this_time = max(this_time, memo[pre]);
      }
      memo[no] = time + this_time;
      max_time = max(max_time, memo[no]);
    }
    cout << max_time << endl;
  }
};

int main() {
  Solution().run();
  return 0;
}

