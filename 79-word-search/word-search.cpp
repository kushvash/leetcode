class Solution {
public:
    bool existHelper(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int start, int currR, int currC) {
        if(start==word.size()){
            return true;
        }
        if(currR>=board.size() || currR<0) {
            return false;
        }
        if(currC>=board[0].size() || currC<0) {
            return false;
        }
        if(visited[currR][currC] || board[currR][currC]!=word[start]) {
            return false;
        }

        visited[currR][currC]=true;

        bool ans = (existHelper(board, visited, word, start+1, currR+1, currC) || existHelper(board, visited, word, start+1, currR, currC+1) || existHelper(board, visited, word, start+1, currR-1, currC) || existHelper(board, visited, word, start+1, currR, currC-1));

        visited[currR][currC]=false;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        // bool res=false;

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(existHelper(board, visited, word, 0, i, j)){
                    return true;
                }
            }
        }

        return false;
    }
};