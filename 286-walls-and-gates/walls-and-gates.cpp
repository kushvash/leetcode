class Solution {
public:
    void bfs(vector<vector<int>>& rooms, int i, int j) {
        vector<vector<int>> dirs={
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        queue<vector<int>> q;

        q.push({i, j, 0});

        while(!q.empty()) {
            int x=q.front()[0], y=q.front()[1], dist=q.front()[2];
            q.pop();

            for(auto& dir: dirs) {
                int xNew=x+dir[0], yNew=y+dir[1];

                if(xNew>=0 && xNew<rooms.size() && yNew>=0 && yNew<rooms[0].size() && rooms[xNew][yNew]!=-1) {
                    if(dist+1<rooms[xNew][yNew]) {
                        rooms[xNew][yNew]=dist+1;
                        q.push({xNew, yNew, dist+1});
                    }
                }
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size(), n=rooms[0].size();

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(rooms[i][j]==0) {
                    bfs(rooms, i, j);
                }
            }
        }

        return;
    }
};