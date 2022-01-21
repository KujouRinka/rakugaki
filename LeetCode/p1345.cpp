class Solution {
public:
    int minJumps(vector<int> &arr) {
        auto sz = arr.size();
        unordered_map<int, vector<int>> count;
        for (int i = 1; i < sz; ++i)
            count[arr[i]].push_back(i);
        vector<int> dist(sz, 0x7fffffff);
        dist[0] = 0;
        queue<int> this_idx;
        this_idx.push(0);

        while (!this_idx.empty()) {
            int idx = this_idx.front();
            if (idx == sz - 1) {
                queue<int>().swap(this_idx);
                break;
            }
            this_idx.pop();
            int f_idx = idx - 1, b_idx = idx + 1;
            if (f_idx >= 0 && dist[f_idx] == 0x7fffffff) {
                dist[f_idx] = dist[idx] + 1;
                this_idx.push(f_idx);
            }
            if (b_idx < sz && dist[b_idx] == 0x7fffffff) {
                dist[b_idx] = dist[idx] + 1;
                this_idx.push(b_idx);
            }
            for (int i: count[arr[idx]]) {
                if (dist[i] == 0x7fffffff) {
                    dist[i] = dist[idx] + 1;
                    this_idx.push(i);
                }
            }
            count.erase(arr[idx]);
        }

        return dist[sz - 1];
    }
};

