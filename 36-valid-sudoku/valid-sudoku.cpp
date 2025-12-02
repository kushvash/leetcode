class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<int>> row;
        unordered_map<int, set<int>> col;
        map<pair<int, int>, set<int>> blocks;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j]!='.') {
                    int ele=board[i][j]-'0';
                    if(row[i].find(ele)!=row[i].end()) {
                        return false;
                    }
                    if(col[j].find(ele)!=col[j].end()) {
                        return false;
                    }
                    if(blocks[{i/3, j/3}].find(ele)!=blocks[{i/3, j/3}].end()) {
                        return false;
                    }

                    row[i].insert(ele);
                    col[j].insert(ele);
                    blocks[{i/3, j/3}].insert(ele);
                }
            }
        }

        return true;
    }
};