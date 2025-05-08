class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        const long long INF = LLONG_MAX / 4;
        // dist[i][j][k]: minimum time to reach (i,j) when next move cost = (k==0?1:2)
        vector<vector<array<long long,2>>> dist(n, vector<array<long long,2>>(m, {INF, INF}));
        using State = tuple<long long,int,int,int>; // (time, i, j, parity)
        priority_queue<State, vector<State>, greater<State>> pq;

        // start at (0,0) with next‐move cost = 1 (parity = 0)
        dist[0][0][0] = 0;
        pq.emplace(0LL, 0, 0, 0);

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [t, i, j, k] = pq.top(); 
            pq.pop();
            if (t > dist[i][j][k]) continue;

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                long long moveCost = (k == 0 ? 1 : 2);
                // you can only start moving into (ni,nj) at time >= moveTime[ni][nj]
                long long startTime = max(t, (long long)moveTime[ni][nj]);
                long long arriveTime = startTime + moveCost;
                int nk = k ^ 1;

                if (arriveTime < dist[ni][nj][nk]) {
                    dist[ni][nj][nk] = arriveTime;
                    pq.emplace(arriveTime, ni, nj, nk);
                }
            }
        }

        long long ans = min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
        return (int)ans;
    }
};

//time : O(ElogV)=O(4nm⋅log(2nm))=O(nmlog(nm)) 
//Space: O(nm)