class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Build graph and in-degree array
        for (const auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            order.push_back(curr);

            for (int neighbor : graph[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        } else {
            return {}; // cycle detected, no valid order
        }
    }
};
