class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> blocks;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char num=board[i][j];

                if(num=='.') {
                    continue;
                }

                pair<int, int> currPair={i/3, j/3};

                if(rows[i].find(num)!=rows[i].end() || cols[j].find(num)!=cols[j].end() || blocks[currPair].find(num)!=blocks[currPair].end()) {
                    return false;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                blocks[currPair].insert(num);
            }
        }

        return true;
    }
};