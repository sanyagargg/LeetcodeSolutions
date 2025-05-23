class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            k -= (1 - nums[right]);
            while (k < 0) {
                k += (1 - nums[left]);
                ++left;
            }
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};