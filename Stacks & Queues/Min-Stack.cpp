class MinStack {
public:
    MinStack() {
        // No initialization needed
    }

    void push(int val) {
        if (stack_.empty()) {
            stack_.emplace(val, val);
        } else {
            int current_min = std::min(val, stack_.top().second);
            stack_.emplace(val, current_min);
        }
    }

    void pop() {
        if (!stack_.empty()) {
            stack_.pop();
        }
    }

    int top() const {
        return stack_.top().first;
    }

    int getMin() const {
        return stack_.top().second;
    }

private:
    std::stack<std::pair<int, int>> stack_; // Each pair: {value, current_min}
};