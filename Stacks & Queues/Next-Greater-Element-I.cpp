#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> mono_stack;

        for (int num : nums2) {
            while (!mono_stack.empty() && mono_stack.top() < num) {
                next_greater[mono_stack.top()] = num;
                mono_stack.pop();
            }
            mono_stack.push(num);
        }

        std::vector<int> result;
        for (int num : nums1) {
            result.push_back(next_greater.count(num) ? next_greater[num] : -1);
        }

        return result;
    }
};
