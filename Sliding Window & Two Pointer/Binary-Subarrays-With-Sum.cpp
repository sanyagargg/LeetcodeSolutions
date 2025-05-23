class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(const std::vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int count = 0, sum = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
};