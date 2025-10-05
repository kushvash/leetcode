class Solution {
public:
    void allPathsSourceTargetHelper(vector<vector<int>>& graph, unordered_set<int>& visited, int ele, int n, vector<int>& curr, vector<vector<int>>& res) {
        if(ele==n) {
            res.push_back(curr);
        }

        for(int& i: graph[ele]) {
            if(visited.find(i)==visited.end()) {
                visited.insert(i);
                curr.push_back(i);

                allPathsSourceTargetHelper(graph, visited, i, n, curr, res);

                curr.pop_back();
                visited.erase(i);
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // unordered_map<int, vector<int>> newGraph;
        unordered_set<int> visited;
        vector<int> curr;
        curr.push_back(0);
        vector<vector<int>> res;

        int n=graph.size();



        allPathsSourceTargetHelper(graph, visited, 0, graph.size()-1, curr, res);
    
        return res;
    }
};