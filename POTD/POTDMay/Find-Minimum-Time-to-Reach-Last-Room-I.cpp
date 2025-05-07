class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        // dist[i][j] = earliest time we can arrive at (i,j)
        vector<vector<long long>> dist(n, vector<long long>(m, LLONG_MAX));
        // min-heap of (time, i, j)
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        // start at (0,0) at time 0
        dist[0][0] = 0;
        pq.emplace(0LL, 0, 0);

        // 4 directions
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            // if we've already found a better way here, skip
            if (t > dist[i][j]) continue;
            // reached target
            if (i == n-1 && j == m-1) {
                return t;
            }
            // try all neighbors
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                // earliest we can start moving into (ni,nj) is max(t, moveTime[ni][nj])
                // plus 1 second to actually move
                long long arrive = max(t, (long long)moveTime[ni][nj]) + 1;
                if (arrive < dist[ni][nj]) {
                    dist[ni][nj] = arrive;
                    pq.emplace(arrive, ni, nj);
                }
            }
        }

        // problem guarantees reachability under the rules
        return -1;
    }
};