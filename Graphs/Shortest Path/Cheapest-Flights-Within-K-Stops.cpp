class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency list for the graph representation
        vector<vector<pair<int, int>>> graph(n);
        
        // Fill the graph with the flight data
        for (const auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        
        // Min-heap to process the city with the least cost first
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Distance array to track minimum cost to reach (city, stops)
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        
        // Start from the source city with 0 cost and 0 stops
        pq.push({0, {src, 0}});
        dist[src][0] = 0;
        
        // Process the priority queue
        while (!pq.empty()) {
            int cost = pq.top().first;
            int city = pq.top().second.first;
            int stops = pq.top().second.second;
            pq.pop();
            
            // If we reach the destination city, return the cost
            if (city == dst) {
                return cost;
            }
            
            // If the number of stops exceeds k, continue (ignore this path)
            if (stops > k) {
                continue;
            }
            
            // Explore neighbors
            for (const auto& neighbor : graph[city]) {
                int nextCity = neighbor.first;
                int nextCost = cost + neighbor.second;
                
                // If this path is cheaper, update the distance and push to priority queue
                if (nextCost < dist[nextCity][stops + 1]) {
                    dist[nextCity][stops + 1] = nextCost;
                    pq.push({nextCost, {nextCity, stops + 1}});
                }
            }
        }
        
        // If no valid path is found, return -1
        return -1;
    }
};
