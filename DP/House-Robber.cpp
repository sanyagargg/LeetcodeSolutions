class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev1 = nums[0];             // max money if we rob up to house i-2
        int prev2 = max(nums[0], nums[1]); // max money if we rob up to house i-1

        for (int i = 2; i < n; i++) {
            int curr = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};
