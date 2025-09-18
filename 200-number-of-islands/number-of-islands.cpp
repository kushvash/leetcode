class Solution {
public:
    void removeIsland(vector<vector<char>>& grid, int i, int j) {
        vector<vector<int>> dirs={
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        queue<pair<int, int>> toVisit;

        toVisit.push({i, j});
        grid[i][j]='0';

        while(!toVisit.empty()) {
            pair<int, int> currPair=toVisit.front();
            toVisit.pop();
            for(int i=0; i<4; i++) {
                int tempX=currPair.first+dirs[i][0];
                int tempY=currPair.second+dirs[i][1];
                if(tempX>=0 && tempX<grid.size() && tempY>=0 && tempY<grid[0].size() && grid[tempX][tempY]=='1') {
                    grid[tempX][tempY]='0';
                    toVisit.push({tempX, tempY});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), count=0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1') {
                    removeIsland(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};