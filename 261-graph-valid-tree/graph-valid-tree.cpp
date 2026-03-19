class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         if ((int)edges.size() != n - 1) return false;

        unordered_map<int, vector<int>> graph;
        graph.reserve(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> seen(n, false);
        queue<int> q;
        q.push(0);
        seen[0] = true;

        int visited = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;

            for (int v : graph[u]) {
                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
            }
        }

        // With n-1 edges, connectivity implies no cycles
        return visited == n;
    }
};