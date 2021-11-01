class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        bitset<200001> candy_set;
        for (int i: candyType)
            candy_set.set(i + 100000);
        return min(candyType.size() / 2, candy_set.count());
    }
};
