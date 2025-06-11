class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list for the graph
        vector<vector<pair<int, int>>> graph(n + 1);
        
        // Fill the graph with the time data
        for (const auto& time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        // Distance array initialized to infinity for all nodes
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0; // Start from the source node k with distance 0
        
        // Min-heap priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); // Push source node with distance 0
        
        while (!pq.empty()) {
            int d = pq.top().first;  // Current distance
            int node = pq.top().second;  // Current node
            pq.pop();
            
            // If the current distance is already larger than the known shortest distance, continue
            if (d > dist[node]) {
                continue;
            }
            
            // Process all the neighbors of the current node
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                // Relax the edge and update distance if a shorter path is found
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        // Find the maximum distance among all nodes
        int result = *max_element(dist.begin() + 1, dist.end());  // Ignoring dist[0] since nodes are 1-indexed
        
        // If any node is still unreachable (i.e., has INF distance), return -1
        return result == INT_MAX ? -1 : result;
    }
};
