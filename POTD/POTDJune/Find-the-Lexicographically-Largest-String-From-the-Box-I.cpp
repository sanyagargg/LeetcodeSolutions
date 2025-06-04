class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int max_length = n - numFriends + 1;

        // If the whole word length equals max_length, just return the word
        if (n == max_length) {
            return word;
        }

        // Step 1: Find the greatest letter in the word
        char greatest_letter = 'a';
        for (int i = 0; i < n; i++) {
            if (word[i] > greatest_letter) {
                greatest_letter = word[i];
            }
        }

        // Step 2: Collect all indices where greatest_letter occurs
        vector<int> greatest_indices_store;
        for (int i = 0; i < n; i++) {
            if (word[i] == greatest_letter) {
                greatest_indices_store.push_back(i);
            }
        }

        // Step 3: Initialize greatest_index with first occurrence
        int greatest_index = greatest_indices_store[0];

        // Step 4: Compare substrings starting at each candidate index to find lex greatest substring
        for (int idx = 1; idx < greatest_indices_store.size(); idx++) {
            int next_greatest_index = greatest_indices_store[idx];

            // Compare substrings of length max_length starting at greatest_index and next_greatest_index
            bool next_is_greater = false;
            for (int j = 0; j < max_length; j++) {
                // If next substring ends earlier, break
                if (next_greatest_index + j >= n) break;
                if (greatest_index + j >= n) break;

                if (word[next_greatest_index + j] > word[greatest_index + j]) {
                    next_is_greater = true;
                    break;
                } else if (word[next_greatest_index + j] < word[greatest_index + j]) {
                    break; // current greatest_index is better, no need to update
                }
                // if equal, continue checking next char
            }

            if (next_is_greater) {
                greatest_index = next_greatest_index;
            }
        }

        // Step 5: Extract substring starting at greatest_index of length max_length
        string result = "";
        for (int i = greatest_index; i < greatest_index + max_length && i < n; i++) {
            result.push_back(word[i]);
        }

        return result;
    }
};
