class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If middle element is greater than the rightmost element, the minimum is in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // If middle element is less than the rightmost element, the minimum is in the left half
            else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};
