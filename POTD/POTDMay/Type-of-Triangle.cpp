class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Sort the sides to make triangle inequality checks easier
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2];

        // Check if it can form a triangle using triangle inequality
        if (a + b <= c) {
            return "none";
        }

        // Check triangle types
        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};
