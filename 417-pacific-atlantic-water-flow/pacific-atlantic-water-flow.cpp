class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> canReach(m, vector<int>(n, 0));
        vector<vector<int>> res;

        queue<pair<int,int>> pacific, atlantic;

        // Initialize boundary cells
        for(int i = 0; i < m; i++) {
            pacific.push({i, 0});
            atlantic.push({i, n - 1});
        }
        for(int j = 0; j < n; j++) {
            pacific.push({0, j});
            atlantic.push({m - 1, j});
        }

        bfs(heights, canReach, pacific, 1, res); // mark Pacific as 1
        bfs(heights, canReach, atlantic, 2, res); // mark Atlantic as 2

        return res;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<int>>& canReach,
             queue<pair<int,int>> q, int ocean, vector<vector<int>>& res) {

        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(visited[x][y]) continue;
            visited[x][y] = true;

            canReach[x][y] += ocean; // mark which ocean this cell can reach
            if(canReach[x][y] == 3)  // 1|2 == 3 → both oceans
                res.push_back({x, y});

            for(auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(visited[nx][ny]) continue;
                if(heights[nx][ny] < heights[x][y]) continue; // water can't flow uphill
                q.push({nx, ny});
            }
        }
    }
};