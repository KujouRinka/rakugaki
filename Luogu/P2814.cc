#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  Solution() = default;

  void run() {
    string input;
    string cur_parent;
    while (true) {
      cin >> input;
      if (input == "$")
        break;
      char mode = input[0];
      string cur = input.substr(1);
      if (name_id.count(cur) == 0) {
        relation.push_back(incr_id);
        id_name[incr_id] = cur;
        name_id[cur] = incr_id++;
      }
      if (mode == '#') {
        cur_parent = cur;
      } else if (mode == '+') {
        add(cur_parent, cur);
      } else {  // mode == '?'
        cout << cur << " " << id_name[find(name_id[cur])] << endl;
      }
    }
  }

 private:
  unordered_map<string, int> name_id;
  unordered_map<int, string> id_name;
  vector<int> relation;
  int incr_id = 0;

  int find(int x) {
    if (relation[x] == x)
      return x;
    return relation[x] = find(relation[x]);
  }

  void add(const string &parent, const string &child) {
    relation[find(name_id[child])] = relation[find(name_id[parent])];
  }
};

int main() {
  Solution().run();
  return 0;
}

