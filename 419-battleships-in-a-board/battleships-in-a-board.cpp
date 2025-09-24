class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        vector<int> dirs;

        if(i<board.size()-1 && board[i+1][j]=='X') {
            dirs={1, 0};
        }else if(j<board[0].size()-1 && board[i][j+1]=='X') {
            dirs={0, 1};
        }else {
            board[i][j]='.';
            // cout<<"single"<<endl;
            return;
        }
        // cout<<dirs[0]<<" "<<dirs[1]<<endl;

        q.push({i, j});

        while(!q.empty()) {
            auto tempP=q.front();
            q.pop();
            board[tempP.first][tempP.second]='.';

            int newI=tempP.first+dirs[0], newJ=tempP.second+dirs[1];

            if(newI<board.size() && newJ<board[0].size() && board[newI][newJ]=='X') {
                q.push({newI, newJ});
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size(), count=0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='X') {
                    cout<<i<<" "<<j<<endl;
                    dfs(board, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};