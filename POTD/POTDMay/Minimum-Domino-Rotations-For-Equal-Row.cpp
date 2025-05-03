class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        // Try both candidates: tops[0] and bottoms[0]
        int res = check(tops[0], tops, bottoms, n);
        if (res != -1) return res;
        return check(bottoms[0], tops, bottoms, n);
    }

private:
    int check(int target, vector<int>& tops, vector<int>& bottoms, int n) {
        int rotations_top = 0;
        int rotations_bottom = 0;

        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1; // Not possible
            }
            if (tops[i] != target) rotations_top++;     // Need to rotate to bring target on top
            if (bottoms[i] != target) rotations_bottom++; // Need to rotate to bring target on bottom
        }

        return min(rotations_top, rotations_bottom);
    }
};


//time : O(N)
//Space : O(1)