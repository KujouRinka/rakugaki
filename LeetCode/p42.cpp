class Solution {
public:
    int trap(vector<int> &height) {
        auto sz = height.size();
        if (sz <= 2)
            return 0;
        int volume = 0;
        int left = 0, right = sz - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > height[left + 1]) {
                    volume += height[left] - height[left + 1];
                    height[left + 1] = height[left];
                }
                ++left;
            } else {
                if (height[right] > height[right - 1]) {
                    volume += height[right] - height[right - 1];
                    height[right - 1] = height[right];
                }
                --right;
            }
        }
        return volume;
    }
};
