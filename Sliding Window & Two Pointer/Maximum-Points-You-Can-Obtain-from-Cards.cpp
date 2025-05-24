class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int window = accumulate(cardPoints.begin(), cardPoints.begin() + n - k, 0);
        int res = total - window;
        for (int i = n - k; i < n; ++i) {
            window -= cardPoints[i - (n - k)];
            window += cardPoints[i];
            res = max(res, total - window);
        }
        return res;
    }
};
