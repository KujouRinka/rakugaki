class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<int> dist(n, 0x3fffffff);
        vector<int> tmpDist(n, 0x3fffffff);
        dist[src] = 0;
        tmpDist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            for (auto &j : flights) {
                tmpDist[j[1]] = min(tmpDist[j[1]], dist[j[0]] + j[2]);
            }
            dist = tmpDist;
        }
        return dist[dst] == 0x3fffffff ? -1 : dist[dst];
    }

    static int min(int a, int b) {
        return a > b ? b : a;
    }
};
