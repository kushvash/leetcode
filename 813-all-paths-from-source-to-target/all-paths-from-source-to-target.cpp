class Solution {
public:
    vector<vector<int>> dfs(int u, int target, const vector<vector<int>>& g, vector<vector<vector<int>>>& memo) {
        if (!memo[u].empty()) return memo[u];
        if (u == target) return memo[u] = {{target}};

        vector<vector<int>> res;
        for (int v : g[u]) {
            auto tails = dfs(v, target, g, memo);
            for (auto& path : tails) {
                vector<int> p; p.reserve(path.size() + 1);
                p.push_back(u);
                p.insert(p.end(), path.begin(), path.end());
                res.push_back(std::move(p));
            }
        }
        return memo[u] = std::move(res);
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<vector<int>>> memo(graph.size());
        vector<int> cur; cur.push_back(0);
        return dfs(0, target, graph, memo);
    }
};