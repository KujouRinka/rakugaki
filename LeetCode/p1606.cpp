class Solution {
    using server_pair = pair<int, int>;
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        set<int> server_pool;
        for (int i = 0; i < k; ++i)
            server_pool.insert(i);
        auto f = [](server_pair &l, server_pair &r) -> bool {
            return l.second > r.second;
        };
        priority_queue<server_pair, vector<server_pair>, decltype(f)> time_hp(f);
        unordered_map<int, int> task_count;
        int max_task = 0;
        vector<int> max_task_server;

        auto sz = arrival.size();
        for (int i = 0; i < sz; ++i) {
            auto which_server = i % k;
            int req_time = arrival[i];
            int req_load = load[i];
            while (!time_hp.empty() && time_hp.top().second <= req_time) {
                auto[server, end_time] = time_hp.top();
                time_hp.pop();
                server_pool.insert(server);
            }
            auto it = server_pool.lower_bound(which_server);
            it = it == server_pool.end() ? server_pool.lower_bound(0) : it;
            if (it == server_pool.end())
                continue;
            time_hp.push({*it, req_time + req_load});
            int task = task_count[*it] + 1;
            if (task > max_task) {
                max_task = task;
                max_task_server.clear();
                max_task_server.push_back(*it);
            } else if (task == max_task) {
                max_task_server.push_back(*it);
            }
            ++task_count[*it];
            server_pool.erase(it);
        }
        return max_task_server;
    }
};

