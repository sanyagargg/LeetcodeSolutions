/* Solution 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash; // hash map to store frequencies

        // storing the frequencies:
        for (int num : nums) {
            hash[num]++;
        }

        // checking the frequencies for numbers:
        for (auto& pair : hash) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        // Return a default value if no single number is found
        return -1;
    }
};
*/

//Solution 2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (int num : nums) {
            single ^= num;
        }
        return single;
    }
};