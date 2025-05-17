/*Brute force approach time O(n^2) and space O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i] <= nums[j]){
                    continue;
                }else{
                    swap(nums[i],nums[j]);
                }
            }
        }
    }
};*/

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1; // 3 pointers

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

/* My approach using map O(n) approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }
        int index = 0;
        for (const auto& pair : frequencyMap) {
            for (int i = 0; i < pair.second; ++i) {
                nums[index++] = pair.first;
            }
        } 
    }
};*/