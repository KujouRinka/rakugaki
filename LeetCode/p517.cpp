class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int cSum = accumulate(machines.begin(), machines.end(), 0);
        int sz = machines.size();
        if (cSum % sz)
            return -1;
        int average = cSum / sz;
        int sum = 0;
        int result = 0;
        for (int i : machines) {
            i -= average;
            sum += i;
            result = max(result, max(abs(sum), i));
        }

        return result;
    }
};
