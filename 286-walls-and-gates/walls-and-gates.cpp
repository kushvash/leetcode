class Solution {
public:
    vector<vector<int>> dirs = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };

    int INF=2147483647;

    void bfs(vector<vector<int>>& rooms, int i, int j) {
        queue<vector<int>> q;

        q.push({i, j, 0}); 
        
        while(!q.empty()) {
            int n=q.size();

            for(int i=0; i<n; i++) {
                vector<int> currPos=q.front();
                q.pop();

                int x=currPos[0];
                int y=currPos[1];
                int dist=currPos[2];

                for(auto& dir: dirs) {
                    int nextX=x+dir[0], nextY=y+dir[1];
                    if(nextX<0 || nextX>=rooms.size() || nextY<0 || nextY>=rooms[0].size()) {
                        continue;
                    }
                    if(rooms[nextX][nextY]==-1 || dist+1>=rooms[nextX][nextY]) {
                        continue;
                    }

                    rooms[nextX][nextY]=dist+1;
                    q.push({nextX, nextY, dist+1});
                }
            }
        }

        return;
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i=0; i<rooms.size(); i++) {
            for(int j=0; j<rooms[0].size(); j++) {
                if(rooms[i][j]==0) {
                    bfs(rooms, i, j);
                }
            }
        }
        return;
    }
};