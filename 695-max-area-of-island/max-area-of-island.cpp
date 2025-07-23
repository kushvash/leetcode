class Solution {
public:
    int maxAreaOfIslandHelper(int row, int col, vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), count=1;

        queue<pair<int, int>> q;

        q.push({row, col});
        grid[row][col]=0;

        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();

            if(r!=0 && grid[r-1][c]==1){
                q.push({r-1,c});
                grid[r-1][c]=0;
                count++;
            }
            if(c!=0 && grid[r][c-1]==1){
                q.push({r,c-1});
                grid[r][c-1]=0;
                count++;
            }
            if(r!=m-1 && grid[r+1][c]==1){
                q.push({r+1,c});
                grid[r+1][c]=0;
                count++;
            }
            if(c!=n-1 && grid[r][c+1]==1){
                q.push({r,c+1});
                grid[r][c+1]=0;
                count++;
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    ans=max(ans, maxAreaOfIslandHelper(i, j, grid));
                }
            }
        }


        return ans;
    }
};