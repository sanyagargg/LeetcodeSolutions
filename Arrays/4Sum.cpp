class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int lo = j + 1, hi = n - 1;

                while (lo < hi) {
                    int twoSum = nums[lo] + nums[hi];
                    if (twoSum == newTarget) {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});

                        // Skip duplicates for the third and fourth numbers
                        while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
                        while (lo < hi && nums[hi] == nums[hi - 1]) --hi;

                        ++lo;
                        --hi;
                    }
                    else if (twoSum < newTarget) {
                        ++lo;
                    }
                    else {
                        --hi;
                    }
                }
            }
        }

        return res;
    }
};
