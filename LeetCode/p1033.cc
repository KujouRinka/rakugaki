class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int s[3] = {a, b, c}; 
        sort(s, s + 3);
        int maxSlot1 = s[1] - s[0] - 1, maxSlot2 = s[2] - s[1] - 1;
        int maxMove = maxSlot1 + maxSlot2, minMove;
        if (maxSlot1 == 0 || maxSlot2 == 0) minMove = min(1, maxMove);
        else if (maxSlot1 == 1 || maxSlot2 == 1) minMove = 1;
        else minMove = 2;
        return {minMove, maxMove};
    }
};

