class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        // Compute sum of non-zero elements and count zeros in each array
        long long s1 = 0, s2 = 0;
        long long z1 = 0, z2 = 0;
        for (int x : nums1) {
            if (x == 0) z1++;
            else s1 += x;
        }
        for (int x : nums2) {
            if (x == 0) z2++;
            else s2 += x;
        }
        
        // Minimal possible sums if each zero is replaced by 1
        long long min1 = s1 + z1;
        long long min2 = s2 + z2;
        
        // Case: neither array has zeros
        if (z1 == 0 && z2 == 0) {
            return (s1 == s2 ? s1 : -1LL);
        }
        // Case: nums1 has no zeros, nums2 does
        if (z1 == 0) {
            // must have final sum = s1, and s1 >= min2 so that zeros in nums2
            // can be assigned positive ints summing to (s1 - s2) ≥ z2
            if (s1 >= min2) return s1;
            else return -1LL;
        }
        // Case: nums2 has no zeros, nums1 does
        if (z2 == 0) {
            if (s2 >= min1) return s2;
            else return -1LL;
        }
        // Case: both have at least one zero
        // We can choose final sum T = max(min1, min2)
        return max(min1, min2);
    }
};
