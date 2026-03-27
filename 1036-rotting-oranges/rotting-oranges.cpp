class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<vector<int>>& q, int& res) {
        vector<pair<int, int>> dirs={
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        int changed=0;

        while(!q.empty()) {
            int n=q.size();
            res++;

            for(int i=0; i<n; i++) {
                int x=q.front()[0], y=q.front()[1];
                q.pop();

                for(auto& [X, Y]: dirs) {
                    int xNew=x+X, yNew=y+Y;

                    if(xNew>=0 && xNew<grid.size() && yNew>=0 && yNew<grid[0].size() && grid[xNew][yNew]==1) {
                        q.push({xNew, yNew});
                        grid[xNew][yNew]=2;      
                        changed++;
                    }
                }
            }
        }

        return changed;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), rotten=0, fresh=0;

        queue<vector<int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                    rotten++;
                }else if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }

        if(fresh==0) {
            return 0;
        }

        int res=-1;
        
        int changed=bfs(grid, q, res);

        if(changed!=fresh) {
            return -1;
        }

        return res;
    }
};