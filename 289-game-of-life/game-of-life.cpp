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
        int deadCount=0, aliveCount=0;

        for(vector<int>& dir: dirs) {
            int newRow=row+dir[0], newCol=col+dir[1];
            
            if(newRow>=0 && newRow<board.size() && newCol>=0 && newCol<board[0].size()) {
                if(board[newRow][newCol]==0) {
                    deadCount++;
                }else {
                    aliveCount++;
                }
            }
        }

        int currCell=board[row][col];
        
        if(currCell==1 && (aliveCount<2 || aliveCount>3)) {
            return 0;
        }

        if(currCell==1 && (aliveCount==2 || aliveCount==3)) {
            return 1;
        }

        if(aliveCount==3) {
            return 1;
        }

        return currCell;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int ROWS=board.size(), COLS=board[0].size();
        vector<vector<int>> newBoard(ROWS, vector<int>(COLS, -1));

        for(int row=0; row<ROWS; row++) {
            for(int col=0; col<COLS; col++) {
                newBoard[row][col]=gameOfLifeHelper(board, row, col);
            }
        }

        for(int row=0; row<ROWS; row++) {
            for(int col=0; col<COLS; col++) {
                board[row][col]=newBoard[row][col];
            }
        }
    }
};