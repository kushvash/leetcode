class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<int>> rows;
        unordered_map<int, set<int>> cols;
        map<pair<int, int>, set<int>> blocks;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j]!='.') {
                    int ele=board[i][j]-'0';
                    pair<int, int> currPair={i/3, j/3};
                    if(rows[i].find(ele)!=rows[i].end() || cols[j].find(ele)!=cols[j].end() || blocks[currPair].find(ele)!=blocks[currPair].end()) {
                        return false;
                    }

                    rows[i].insert(ele);
                    cols[j].insert(ele);
                    blocks[currPair].insert(ele);
                }
            }
        }

        return true;
    }
};