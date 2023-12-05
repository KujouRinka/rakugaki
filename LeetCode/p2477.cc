class Solution {
  using ll = long long;
 public:
  long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
    this->seats = seats;
    for (auto &v : roads) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }

    ll cars, people;
    ll ret = dfs(0, -1, cars, people);
    return ret;
  }

 private:
  int seats;
  unordered_map<ll, vector<ll>> g;

  ll dfs(ll cur, ll from, ll &cars, ll &people) {
    if (g[cur].size() == 1 && g[cur][0] == from) {
      cars = 1;
      people = 1;
      return 0;
    }

    people = 0;
    ll ret = 0;
    for (auto next : g[cur]) {
      if (next == from) {
        continue;
      }
      ll c, p;   // cars and people from last
      ll consumption = dfs(next, cur, c, p);
      people += p;
      ret += consumption + c;
    }
    cars = (people + seats - 1) / seats;
    if (++people > seats * cars) {
      ++cars;
    }
    return ret;
  }
};

