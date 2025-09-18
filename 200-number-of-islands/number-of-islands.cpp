class Solution {
public:
    vector<vector<int>> dirs={
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
    void removeIsland(vector<vector<char>>& grid, int i, int j) {
        for(int k=0; k<4; k++) {
            int tempX=i+dirs[k][0];
            int tempY=j+dirs[k][1];
            if(tempX>=0 && tempX<grid.size() && tempY>=0 && tempY<grid[0].size() && grid[tempX][tempY]=='1') {
                grid[tempX][tempY]='0';
                removeIsland(grid, tempX, tempY);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), count=0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1') {
                    grid[i][j]='0';
                    removeIsland(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};