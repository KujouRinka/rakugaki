class Solution {
public:
    int maxArea(const vector<int> &height) {
        int p_forward = 0, p_back = height.size() - 1;
        int result = 0;
        while (p_forward < p_back) {
            result = max(result, min(height[p_forward], height[p_back]) * (p_back - p_forward));
            if (height[p_forward] < height[p_back])
                ++p_forward;
            else
                --p_back;
        }
        return result;
    }
};
