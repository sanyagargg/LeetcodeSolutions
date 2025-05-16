class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> result(n, -1);
        std::stack<int> indexStack; // Stack to store indices

        for (int i = 0; i < 2 * n; ++i) {
            int current = nums[i % n];
            while (!indexStack.empty() && nums[indexStack.top()] < current) {
                result[indexStack.top()] = current;
                indexStack.pop();
            }
            if (i < n) {
                indexStack.push(i);
            }
        }

        return result;
    }
};
