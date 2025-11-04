class TicTacToe {
public:
    vector<vector<int>> board;
    int n;
    
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0));
        this->n=n;
    }
    
    int move(int row, int col, int player) {
        board[row][col]=player;

        if(checkRow(row, player) || checkCol(col, player) || (row==col && checkDia(player)) || (row==n - col - 1 && checkAntiDia(player))) {
            return player;
        }

        return 0;
    }

    bool checkRow(int row, int player) {
        for(int i=0; i<n; i++) {
            if(board[row][i]!=player) {
                return false;
            }
        }
        return true;
    }

    bool checkCol(int col, int player) {
        for(int i=0; i<n; i++) {
            if(board[i][col]!=player) {
                return false;
            }
        }
        return true;
    }

    bool checkDia(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][row] != player) return false;
        }
        return true;
    }

    bool checkAntiDia(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][n - row - 1] != player) return false;
        }
        return true;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */