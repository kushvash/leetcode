class Solution {
public:
    vector<pair<int, int>> dirs={{1,0}, {-1,0}, {0,1}, {0,-1}};

    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++){
            if(board[i][0]=='O'){
                q.push({i, 0});
            }   
            if(board[i][n-1]=='O'){
                q.push({i, n-1});
            }
        }

        for(int j=0; j<n; j++){
            if(board[0][j]=='O'){
                q.push({0, j});
            }   
            if(board[m-1][j]=='O'){
                q.push({m-1, j});
            }
        }

        bfs(q, board);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='P'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

        return;
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<char>>& board){
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            board[row][col]='P';

            for(int i=0; i<4; i++){
                int r=row+dirs[i].first;
                int c=col+dirs[i].second;

                if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!='O'){
                    continue;
                }

                q.push({r,c});
            }
        }
    }
};