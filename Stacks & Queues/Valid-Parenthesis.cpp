//here time complexity of code is O(nlogn) due to sort
/*class Solution {
public:
    bool isValid(string s) {
        sort(s.begin(), s.end());
        string sorted_string = s;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if ((sorted_string[i] == '(' && sorted_string[i+1] == ')') || 
                    (sorted_string[i] == '{' && sorted_string[i+1] == '}') || 
                    (sorted_string[i] == '[' && sorted_string[i+1] == ']')) {
                    return true;
                }
            }
        }
        return false;
    }
}; 
*/

//in this approach we use maps , which increases time complexity a little as constructing
//map will require space and time
//Constructing the map: O(n), where n is the number of pairs in the map
//Space Complexity:
//Storage space for the map: O(1) for a small fixed number of pairs (3 pairs in this case).
//Additional space for the stack: O(n), where n is the number of characters in the string.
/* class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> matching_brackets = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for (char c : s) {
            // If the current character is an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            }
            else {
                // If the stack is empty or the top of the stack does not match the current closing bracket, return false
                if (brackets.empty() || brackets.top() != matching_brackets[c]) {
                    return false;
                }
                // If the top of the stack matches the current closing bracket, pop it
                brackets.pop();
            }
        }
        
        // If the stack is empty, all brackets are matched, otherwise return false
        return brackets.empty();
    }
}; */


class Solution {
    public:
        bool isValid(std::string s) {
            std::stack<char> brackets;
    
            for (char c : s) {
                // If the current character is an opening bracket, push it onto the stack
                if (c == '(' || c == '{' || c == '[') {
                    brackets.push(c);
                } else {
                    // If the stack is empty or the top of the stack does not match the expected opening bracket, return false
                    if (brackets.empty() || !isMatching(brackets.top(), c)) {
                        return false;
                    }
                    // If the top of the stack matches the expected opening bracket, pop it
                    brackets.pop();
                }
            }
    
            // If the stack is empty, all brackets are matched, otherwise return false
            return brackets.empty();
        }
    
    private:
        bool isMatching(char open, char close) {
            return (open == '(' && close == ')') || 
                   (open == '{' && close == '}') || 
                   (open == '[' && close == ']');
        }
    };
    