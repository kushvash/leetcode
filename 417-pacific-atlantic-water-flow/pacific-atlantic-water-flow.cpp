class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        queue<pair<int, int>> pacQ, atlQ;

        for(int i=0; i<m; i++){
            pacQ.push({i, 0});
            atlQ.push({i, n-1});
        }

        for(int j=0; j<n; j++){
            pacQ.push({0,j});
            atlQ.push({m-1, j});
        }

        bfs(pacQ, pac, heights);
        bfs(atlQ, atl, heights);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &ocean, vector<vector<int>>& heights){
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            ocean[row][col]=true;
            q.pop();
            
            for(int i=0; i<4; i++){
                int r=row+dirs[i].first;
                int c=col+dirs[i].second;

                if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || heights[r][c]<heights[row][col] || ocean[r][c]){
                    continue;
                }

                q.push({r, c});
            }
        }
    }
};