class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> col;
        
        map<pair<int, int>, unordered_set<int>> block;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j]!='.') {
                    int num=board[i][j]-'0';
                    pair<int, int> tempPair={i/3, j/3};
                    if(row[i].find(num)!=row[i].end() || col[j].find(num)!=col[j].end() || block[tempPair].find(num)!=block[tempPair].end()) {
                        return false;
                    }

                    row[i].insert(num);
                    col[j].insert(num);
                    block[tempPair].insert(num);
                }
            }
        }

        return true;
    }
};