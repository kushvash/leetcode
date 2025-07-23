class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), count=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    bfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }

    void bfs(int r, int c, vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<vector<int>> q;
        grid[r][c]='0';

        q.push({r,c});

        while(!q.empty()){
            int row=q.front()[0], col=q.front()[1];
            q.pop();

            if(row>0 && grid[row-1][col]=='1'){
                q.push({row-1, col});
                grid[row-1][col]='0';
            }
            if(col>0 && grid[row][col-1]=='1'){
                q.push({row, col-1});
                grid[row][col-1]='0';
            }
            if(row<m-1 && grid[row+1][col]=='1'){
                q.push({row+1, col});
                grid[row+1][col]='0';
            }
            if(col<n-1 && grid[row][col+1]=='1'){
                q.push({row, col+1});
                grid[row][col+1]='0';
            }
        }
    }
};