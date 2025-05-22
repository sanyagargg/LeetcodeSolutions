class Solution {
public:
    int maxRemoval(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        std::priority_queue<int, std::vector<int>, std::greater<int>> used_query; // Min-heap
        std::priority_queue<int> available_query; // Max-heap

        // Sort queries by start index
        std::sort(queries.begin(), queries.end());

        int query_pos = 0;
        int applied_count = 0;

        for (int i = 0; i < n; ++i) {
            // Add all queries starting at index i
            while (query_pos < queries.size() && queries[query_pos][0] == i) {
                available_query.push(queries[query_pos][1]);
                ++query_pos;
            }

            // Adjust nums[i] by subtracting the number of active queries covering it
            nums[i] -= used_query.size();

            // Apply available queries to reduce nums[i] to zero
            while (nums[i] > 0 && !available_query.empty() && available_query.top() >= i) {
                used_query.push(available_query.top());
                available_query.pop();
                --nums[i];
                ++applied_count;
            }

            // If nums[i] couldn't be reduced to zero
            if (nums[i] > 0) {
                return -1;
            }

            // Remove queries that end at index i from used_query
            while (!used_query.empty() && used_query.top() == i) {
                used_query.pop();
            }
        }

        return queries.size() - applied_count;
    }
};