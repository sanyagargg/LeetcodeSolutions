class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int res = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1) --k;
            while (k < 0) {
                if (nums[left++] % 2 == 1) ++k;
            }
            res += right - left + 1;
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
