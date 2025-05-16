class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int maxArea = 0;
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);

        for (const auto& row : matrix) {
            // Update the histogram heights
            for (int i = 0; i < cols; ++i) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            // Compute the largest rectangle area for the current histogram
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(const std::vector<int>& heights) {
        std::stack<int> st;
        std::vector<int> extendedHeights = heights;
        extendedHeights.push_back(0); // Sentinel to ensure stack is emptied
        int maxArea = 0;

        for (int i = 0; i < extendedHeights.size(); ++i) {
            while (!st.empty() && extendedHeights[i] < extendedHeights[st.top()]) {
                int height = extendedHeights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
