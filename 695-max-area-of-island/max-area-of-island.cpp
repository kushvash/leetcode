class Solution {
public:
    int areaOfIsland(int i, int j, vector<vector<int>>& grid) {
        if(grid[i][j]==0){
            return 0;
        }

        grid[i][j]=0;
        int count=1;

        if(i>0){
            count+=areaOfIsland(i-1, j, grid);
        }
        if(j>0){
            count+=areaOfIsland(i, j-1, grid);
        }
        if(i<grid.size()-1){
            count+=areaOfIsland(i+1, j, grid);
        }
        if(j<grid[0].size()-1){
            count+=areaOfIsland(i, j+1, grid);
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), maxIslands=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    maxIslands=max(maxIslands, areaOfIsland(i, j, grid));
                }
            }
        }

        return maxIslands;
    }
};