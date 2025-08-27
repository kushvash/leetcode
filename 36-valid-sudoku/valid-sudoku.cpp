class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        unordered_map<int, unordered_set<int>> row, col;
        map<pair<int, int>, unordered_set<int>> block;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]!='.'){
                    pair<int, int> currBlock={i/3, j/3};
                    int temp=board[i][j];

                    if(row[i].find(temp)!=row[i].end() || col[j].find(temp)!=col[j].end() || block[currBlock].find(temp)!=block[currBlock].end()){
                        return false;
                    }

                    row[i].insert(temp);
                    col[j].insert(temp);
                    block[currBlock].insert(temp);
                }
            }
        }

        return true;
    }
};