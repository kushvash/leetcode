class Solution {
public:
    void markIsland(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& record){
        if(record[i][j]){
            return;
        }

        record[i][j]=true;

        if(i!=0 && grid[i-1][j]=='1'){
            markIsland(i-1, j, m, n, grid, record);
        }

        if(j!=0 && grid[i][j-1]=='1'){
            markIsland(i, j-1, m, n, grid, record);
        } 

        if(i!=m-1 && grid[i+1][j]=='1'){
            markIsland(i+1, j, m, n, grid, record);
        }

        if(j!=n-1 && grid[i][j+1]=='1'){
            markIsland(i, j+1, m, n, grid, record);    
        } 

        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), count=0;

        vector<vector<bool>> record(m, vector<bool> (n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !record[i][j]){
                    markIsland(i, j, m, n, grid, record);
                    count++;
                }
            }
        }

        return count;
    }
};