class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        // Perform binary search on eating speed k
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;
            
            // Calculate the total hours Koko would take at speed mid
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;  // Equivalent to ceil(pile / mid)
            }
            
            // If total hours is less than or equal to h, try a smaller speed
            if (hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;  // The smallest speed that works
    }
};
