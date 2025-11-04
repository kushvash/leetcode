class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int o=grid[i][j];
                if(o==1) {
                    fresh++;
                } else if(o==2) {
                    q.push({i, j});
                }
            }
        }

        if(fresh==0) {
            return 0;
        }

        int res=-1;

        vector<pair<int, int>> dirs={
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while(!q.empty()) {
            int sz=q.size();
            res++;

            for(int i=0; i<sz; i++) {
                int currRow=q.front().first;
                int currCol=q.front().second;
                q.pop();

                for(pair<int, int>& dir: dirs) {
                    int newRow=currRow+dir.first;
                    int newCol=currCol+dir.second;

                    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1) {
                        q.push({newRow, newCol});        
                        grid[newRow][newCol]=2;                    
                        fresh--;
                    }
                }

            }
        }

        if(fresh==0) {
            return res;
        }

        return -1;
    }
};