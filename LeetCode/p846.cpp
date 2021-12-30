class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int sz = hand.size();
        if (sz % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> count_map;
        for (int i: hand)
            ++count_map[i];
        for (int i = 0; i < sz;) {
            int first_card = hand[i];
            int min_card_num = count_map[first_card];
            for (int j = 0; j < groupSize; ++j) {
                if ((count_map[first_card + j] -= min_card_num) < 0)
                    return false;
            }
            while (i < sz && count_map[hand[i]] == 0)
                ++i;
        }

        return true;
    }
};

