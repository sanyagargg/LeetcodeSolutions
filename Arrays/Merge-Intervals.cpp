class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last = merged.back();
            if (intervals[i][0] <= last[1]) {
                // Overlapping intervals, merge them
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // Non-overlapping, add new interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
