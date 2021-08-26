class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0;
        int ptr1 = 0, ptr2 = people.size() - 1;
        while (ptr1 <= ptr2) {
            if (people[ptr1] + people[ptr2] <= limit)
                ++ptr1;
            --ptr2;
            ++boat;
        }
        return boat;
    }
};
