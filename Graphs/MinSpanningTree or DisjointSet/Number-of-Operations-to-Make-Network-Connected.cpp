class Solution {
public:
    int findParent(int u, vector<int>& parent) {
        if (u != parent[u])
            parent[u] = findParent(parent[u], parent);
        return parent[u];
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pu == pv) return; // already connected

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1; // Not enough cables

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        int components = n;

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu != pv) {
                unionSet(pu, pv, parent, rank);
                components--; // one less component
            }
        }

        return components - 1; // Minimum operations = components - 1
    }
};
