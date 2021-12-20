class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        int sz_house = houses.size(), sz_heater = heaters.size();

        int dis;
        for (int p_house = 0, p_heater = 0; p_house < sz_house; ++p_house) {
            int cur_dis = abs(houses[p_house] - heaters[p_heater]);
            while (p_heater < sz_heater - 1
                   && abs(houses[p_house] - heaters[p_heater])
                      >= (dis = abs(houses[p_house] - heaters[p_heater + 1]))) {
                cur_dis = min(cur_dis, dis);
                ++p_heater;
            }
            radius = max(radius, cur_dis);
        }
        return radius;
    }
};

