class Solution {
public:
    string robotWithString(string s) {
        // Step 1: Count how many times each character appears in s
        vector<int> remaining(26, 0);  // Only lowercase letters

        for (char ch : s) {
            remaining[ch - 'a']++;  // Count each character
        }

        stack<char> t;         // Stack t: holds characters the robot has picked from s
        string result = "";    // Final output: the written string

        // Step 2: Go through each character in s
        for (char ch : s) {
            t.push(ch);                      // Push current char into robot's hand (stack t)
            remaining[ch - 'a']--;           // Decrement the count of this character in remaining

            // Step 3: While we can write the smallest possible character, do it
            while (!t.empty()) {
                // Find the smallest character still remaining in s
                char smallestLeft = '{';     // '{' is one char after 'z', acts as sentinel max
                for (int i = 0; i < 26; ++i) {
                    if (remaining[i] > 0) {
                        smallestLeft = 'a' + i;
                        break;
                    }
                }

                // If the top of stack is <= smallest remaining char in s, we can safely write it
                if (t.top() <= smallestLeft) {
                    result += t.top();       // Add to result string
                    t.pop();                 // Remove from robot's hand
                } else {
                    break;                   // Otherwise, wait to pick more letters from s
                }
            }
        }

        // Step 4: Write all remaining letters from t to result
        while (!t.empty()) {
            result += t.top();  // Write the letter to result
            t.pop();            // Remove from t
        }

        return result;  // Return the final written string
    }
};