class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())
            return {};
        int front = 0, back = nums.size() - 1;
        int r_front = 0, r_back = back;
        vector<int> r(nums.size());
        while (front < back) {
            if (nums[front] & 1)
                r[r_front++] = nums[front++];
            else
                r[r_back--] = nums[front++];
            
            if (nums[back] & 1)
                r[r_front++] = nums[back--];
            else
                r[r_back--] = nums[back--];
        }
        if (front == back)
            r[r_front] = nums[front];
        return r;
    }
};
