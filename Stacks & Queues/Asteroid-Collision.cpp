class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> stack;

        for (int a : asteroids) {
            bool destroyed = false;
            while (!stack.empty() && a < 0 && stack.back() > 0) {
                if (stack.back() < -a) {
                    stack.pop_back();
                    continue;
                } else if (stack.back() == -a) {
                    stack.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                stack.push_back(a);
            }
        }

        return stack;
    }
};
