class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        // Encode new value at each index using modular arithmetic
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        }
        // Extract new values
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] / n;
        }
        return nums;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
