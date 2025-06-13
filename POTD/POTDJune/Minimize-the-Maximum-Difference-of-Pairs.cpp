class Solution {
public:
    bool canFormPairs(const vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int i = 0;
        while (i + 1 < nums.size()) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                count++;
                i += 2; // use both indices
            } else {
                i++;
            }
            if (count >= p) return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums.back() - nums.front();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canFormPairs(nums, p, mid)) {
                high = mid;  // try smaller max diff
            } else {
                low = mid + 1;  // increase max diff
            }
        }
        
        return low;
    }
};