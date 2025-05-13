class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, columns;
        map<pair<int, int>, unordered_set<int>> block;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    pair<int, int> currPair = {i/3, j/3};

                    if(rows[i].count(board[i][j]) || columns[j].count(board[i][j]) || block[currPair].count(board[i][j])){
                        return false;
                    }

                    rows[i].insert(board[i][j]);
                    columns[j].insert(board[i][j]);
                    block[currPair].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};