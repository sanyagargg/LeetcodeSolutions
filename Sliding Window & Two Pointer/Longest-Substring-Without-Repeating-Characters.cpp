class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex; // stores character and its latest index
        int maxLength = 0;
        int left = 0; // left pointer of the window

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            // If character is already in map and its index is >= left pointer
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left) {
                // Move left pointer right after the last occurrence of currentChar
                left = charIndex[currentChar] + 1;
            }

            // Update or add the current character's index
            charIndex[currentChar] = right;

            // Update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};