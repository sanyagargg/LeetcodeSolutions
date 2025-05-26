class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        
        // Build the graph
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> colorCount(n, vector<int>(26, 0));
        
        // Topological sort initialization
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int visited = 0;
        int maxColorValue = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;
            
            int colorIndex = colors[node] - 'a';
            colorCount[node][colorIndex]++;
            maxColorValue = max(maxColorValue, colorCount[node][colorIndex]);
            
            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    colorCount[neighbor][c] = max(colorCount[neighbor][c], colorCount[node][c]);
                }
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return visited == n ? maxColorValue : -1;
    }
};
