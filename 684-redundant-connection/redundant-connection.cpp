class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x], parent); // path compression
        return parent[x];
    }

    bool unite(int a, int b, vector<int>& parent, vector<int>& sz) {
        a = find(a, parent);
        b = find(b, parent);
        if (a == b) return false;

        // union by size
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size(); // nodes are 1..n in this problem
        vector<int> parent(n + 1), sz(n + 1, 1);

        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (!unite(u, v, parent, sz)) {
                return {u, v};
            }
        }

        return {};
    }
};