class Solution {
 public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    unordered_map<int, unordered_set<int>> x_to_y;
    for_each(obstacles.begin(), obstacles.end(), [&x_to_y](auto &v) {
      x_to_y[v[0]].insert(v[1]);
    });

    int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    struct {
      int ret = 0;
      int cur_x = 0;
      int cur_y = 0;
      int di = 3;
    } pars;

    return accumulate(commands.begin(), commands.end(), pars, [&x_to_y, &dirs](auto pars, auto cmd) {
      if (cmd < 0) {
        pars.di = (pars.di + (cmd == -2 ? -1 : 1) + 4) % 4;
      } else {
        while (cmd--) {
          int nx = pars.cur_x + dirs[pars.di][0];
          int ny = pars.cur_y + dirs[pars.di][1];
          if (x_to_y[nx].count(ny)) {
            break;
          }
          pars.cur_x = nx;
          pars.cur_y = ny;
          pars.ret = max(pars.ret, pars.cur_x * pars.cur_x + pars.cur_y * pars.cur_y);
        }
      }
      return std::move(pars);
    }).ret;
  }
};

