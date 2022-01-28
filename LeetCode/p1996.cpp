class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end());
        auto sz = properties.size();
        int result = 0;
        int cur_attack = properties.back()[0];
        int max_attack = properties.back()[0];
        int current_defense_max = -1;
        int max_defense = -1;
        for (int i = sz - 1; i >= 0; --i) {
            if (cur_attack != properties[i][0]) {
                max_defense = max(max_defense, current_defense_max);
                current_defense_max = -1;
                cur_attack = properties[i][0];
            }
            if (properties[i][0] < max_attack && properties[i][1] < max_defense)
                ++result;
            if (properties[i][1] > current_defense_max)
                current_defense_max = properties[i][1];
        }
        return result;
    }
};

