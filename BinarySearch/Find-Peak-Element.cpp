class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If middle element is smaller than the next element, peak must be on the right side
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // If middle element is smaller than the previous element, peak must be on the left side
            else {
                right = mid;
            }
        }
        
        return left;  // At the end, left == right, which will be the peak index
    }
};
