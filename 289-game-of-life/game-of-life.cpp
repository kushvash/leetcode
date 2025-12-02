class Solution {
public:
    vector<vector<int>> dirs = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    };

    int gameOfLifeHelper(vector<vector<int>>& board, int row, int col) {
        int aliveCount=0;

        for(vector<int>& dir: dirs) {
            int newRow=row+dir[0], newCol=col+dir[1];
            
            if(newRow>=0 && newRow<board.size() && newCol>=0 && newCol<board[0].size()) {
                if(board[newRow][newCol]==1 || board[newRow][newCol]==-1) {
                    aliveCount++;
                }
            }
        }

        int currCell=board[row][col];
        
        if (currCell == 1) {
            if (aliveCount < 2 || aliveCount > 3) {
                return -1; // die
            }
            else {
                return 1; // stay alive
            }
        } else {
            if (aliveCount == 3) {
                return 2; 
            }
            else {
                return 0; 
            }
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        int ROWS=board.size(), COLS=board[0].size();
        vector<vector<int>> newBoard(ROWS, vector<int>(COLS, -1));

        for(int row=0; row<ROWS; row++) {
            for(int col=0; col<COLS; col++) {
                board[row][col]=gameOfLifeHelper(board, row, col);
            }
        }

        for(int row=0; row<ROWS; row++) {
            for(int col=0; col<COLS; col++) {
                if(board[row][col]==-1) {
                    board[row][col]=0;
                }else if(board[row][col]==2) {
                    board[row][col]=1;
                }
            }
        }
    }
};