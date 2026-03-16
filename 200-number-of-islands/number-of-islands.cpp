class Solution {
public:
    vector<pair<int, int>> dirs={
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        grid[row][col]='0';
        q.push({row, col});

        while(!q.empty()) {
            pair<int, int> fr=q.front();

            q.pop();

            for(auto& [x, y]: dirs) {
                int newX=fr.first+x;
                int newY=fr.second+y;

                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]=='1') {
                    grid[newX][newY]='0';
                    q.push({newX, newY});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};