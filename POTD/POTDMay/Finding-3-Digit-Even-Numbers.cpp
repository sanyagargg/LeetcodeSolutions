class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> result;
        
        // Iterate over all combinations of 3 digits
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    // Skip if any two indices are the same
                    if (i == j || j == k || i == k) continue;
                    
                    // Form the 3-digit number
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    
                    // Ensure it's a 3-digit number and even
                    if (num >= 100 && num % 2 == 0) {
                        result.insert(num);
                    }
                }
            }
        }
        
        // Convert the set to a vector and return
        vector<int> sorted_result(result.begin(), result.end());
        return sorted_result;
    }
};
