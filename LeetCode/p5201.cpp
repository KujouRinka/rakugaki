class Solution {
public:
    int wateringPlants(const vector<int> &plants, int capacity) {
        int next_plant_idx = 0;
        int sz = plants.size();
        int total_step = 0;
        while (next_plant_idx != sz) {
            int water = capacity;
            total_step += next_plant_idx;
            while (next_plant_idx != sz && plants[next_plant_idx] <= water) {
                water -= plants[next_plant_idx++];
                ++total_step;
            }
            if (next_plant_idx != sz)
                total_step += next_plant_idx;
        }
        return total_step;
    }
};
