class Solution {
public:
    int find(int u, unordered_map<int, int>& parent) {
        if (parent[u] != u)
            parent[u] = find(parent[u], parent);
        return parent[u];
    }

    void unite(int u, int v, unordered_map<int, int>& parent) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu != pv)
            parent[pu] = pv;
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;
        
        // Assign parent for both rows and cols uniquely: offset cols to avoid collision with rows
        for (auto& stone : stones) {
            int row = stone[0];
            int col = ~(stone[1]); // use bitwise NOT to differentiate row & col
            if (!parent.count(row)) parent[row] = row;
            if (!parent.count(col)) parent[col] = col;
            unite(row, col, parent);
        }

        unordered_set<int> uniqueRoots;
        for (auto& [node, _] : parent) {
            uniqueRoots.insert(find(node, parent));
        }

        // Max stones removed = total stones - number of connected components
        return stones.size() - uniqueRoots.size();
    }
};
