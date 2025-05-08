class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;           // Pointer for nums1
        int j = n - 1;           // Pointer for nums2
        int k = m + n - 1;       // Pointer for final position in nums1

        // Merge from the end to avoid overwriting values in nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 is not yet fully copied
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
