class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row, col;
        map<pair<int, int>, unordered_set<int>> blocks;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int num=board[i][j];

                    if(row[i].find(num)!=row[i].end() || col[j].find(num)!=col[j].end() || blocks[{i/3, j/3}].find(num)!=blocks[{i/3, j/3}].end()){
                        return false;
                    }

                    row[i].insert(num);
                    col[j].insert(num);
                    blocks[{i/3, j/3}].insert(num);
                }
            }
        }

        return true;
    }
};