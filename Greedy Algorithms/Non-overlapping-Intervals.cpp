class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // At least one interval is always non-overlapping
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= prev_end) {
                // No overlap
                count++;
                prev_end = intervals[i][1];
            }
        }

        // Total intervals - non-overlapping = intervals to remove
        return intervals.size() - count;
    }
};
