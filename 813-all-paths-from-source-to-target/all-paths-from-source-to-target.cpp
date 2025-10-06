class Solution {
public:
    void dfs(int u, int target, const vector<vector<int>>& g, vector<int>& path, vector<vector<int>>& res) {
        if (u == target) { 
            res.push_back(path); 
            return; 
        }
    
        for (int v : g[u]) {
            path.push_back(v);
            dfs(v, target, g, path, res);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curr;
        curr.push_back(0);
        vector<vector<int>> res;

        int n=graph.size();



        dfs(0, graph.size()-1, graph, curr, res);
    
        return res;
    }
};