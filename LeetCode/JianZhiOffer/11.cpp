class Solution {
public:
    int minArray(vector<int> &numbers) {
        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            int mid = (start + end) >> 1;
            if (numbers[mid] > numbers[end])
                start = mid + 1;
            else if (numbers[mid] < numbers[end])
                end = mid;
            else
                end--;
        }
        return numbers[end];
    }
};
