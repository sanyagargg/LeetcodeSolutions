class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int lo = i + 1, hi = n - 1;
            
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                if (sum == target) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    // Skip duplicates for the second and third elements
                    while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
                    while (lo < hi && nums[hi] == nums[hi - 1]) --hi;
                    ++lo; 
                    --hi;
                }
                else if (sum < target) ++lo;
                else --hi;
            }
        }
        
        return res;
    }
};
