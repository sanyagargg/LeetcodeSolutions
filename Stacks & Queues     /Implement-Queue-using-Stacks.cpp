class MyQueue {
public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        peek(); // Ensure output has the current elements
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }

private:
    std::stack<int> input;
    std::stack<int> output;
};
