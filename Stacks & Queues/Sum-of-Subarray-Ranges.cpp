class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        return compute(nums, std::less<int>()) - compute(nums, std::greater<int>());
    }

private:
    long long compute(const std::vector<int>& nums, const std::function<bool(int, int)>& comp) {
        int n = nums.size();
        std::vector<int> prev(n, -1), next(n, n);
        std::stack<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && comp(nums[stk.top()], nums[i])) {
                next[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) {
                prev[i] = stk.top();
            }
            stk.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += static_cast<long long>(nums[i]) * (i - prev[i]) * (next[i] - i);
        }
        return res;
    }
};
