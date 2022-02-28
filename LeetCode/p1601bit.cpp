class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int r = 0;
        uint32_t opt = UINT16_MAX;
        int check_arr[20];
        int r_size = requests.size();
        for (uint32_t i = 0; i <= opt; ++i) {
            int bit_count = 0;
            memset(check_arr, 0, sizeof(check_arr));
            for (int j = 0; j < r_size; ++j) {
                if (i & (1 << j)) {
                    ++bit_count;
                    --check_arr[requests[j][0]];
                    ++check_arr[requests[j][1]];
                }
            }
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (check_arr[j] != 0) {
                    f = false;
                    break;
                }
            }
            if (f && bit_count > r)
                r = bit_count;
        }
        return r;
    }
};

