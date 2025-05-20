#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        // diff-array for coverage count
        vector<int> diff(n+1, 0);
        
        // build diff: for each [l, r], do +1 at l, -1 at r+1
        for (auto &qr : queries) {
            int l = qr[0];
            int r = qr[1];
            diff[l] += 1;
            if (r + 1 < n) 
                diff[r+1] -= 1;
        }
        
        // prefix-sum -> cover[i] = number of queries covering i
        vector<int> cover(n);
        cover[0] = diff[0];
        for (int i = 1; i < n; ++i) {
            cover[i] = cover[i-1] + diff[i];
        }
        
        // check feasibility: must have cover[i] >= nums[i] for all i
        for (int i = 0; i < n; ++i) {
            if (cover[i] < nums[i]) 
                return false;
        }
        
        return true;
    }
};
