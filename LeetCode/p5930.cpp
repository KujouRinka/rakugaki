class Solution {
public:
    int maxDistance(const vector<int> &colors) {
        int result = 0;
        int front = 0, back = colors.size() - 1;
        while (front < back) {
            if (colors[front] != colors[back]) {
                result = max(result, abs(front - back));
                break;
            }
            if (colors[front + 1] != colors[front])
                ++front;
            else
                --back;
        }
        front = 0, back = colors.size() - 1;
        while (front < back) {
            if (colors[front] != colors[back]) {
                result = max(result, abs(front - back));
                break;
            }
            if (colors[back] != colors[back - 1])
                --back;
            else
                ++front;
        }
        return result;
    }
};
