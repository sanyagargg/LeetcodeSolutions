class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::vector<char> stack;

        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                --k;
            }
            stack.push_back(digit);
        }

        // Remove remaining digits from the end if k > 0
        while (k-- > 0 && !stack.empty()) {
            stack.pop_back();
        }

        // Build the result string and remove leading zeros
        std::string result;
        bool leadingZero = true;
        for (char c : stack) {
            if (leadingZero && c == '0') continue;
            leadingZero = false;
            result += c;
        }

        return result.empty() ? \0\ : result;
    }
};
