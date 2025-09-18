class Solution {
public:
    vector<vector<int>> dirs={
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    int areaOfIsland(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        grid[i][j]=0;
        q.push({i, j});
        int area=1;

        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            for(int k=0; k<4; k++) {
                int tempX=curr.first+dirs[k][0];
                int tempY=curr.second+dirs[k][1];
                
                if(tempX>=0 && tempX<grid.size() && tempY>=0 && tempY<grid[0].size() && grid[tempX][tempY]==1) {
                    grid[tempX][tempY]=0;
                    q.push({tempX, tempY});
                    area++;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0, m=grid.size(), n=grid[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    maxArea=max(maxArea, areaOfIsland(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};