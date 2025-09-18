class Solution {
public:
    bool existHelper(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<bool>>& visited) {
        if(k==word.size()) {
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j] || word[k]!=board[i][j]) {
            return false;
        }

        visited[i][j]=true;
        bool ans=existHelper(board, word, i+1, j, k+1, visited) || existHelper(board, word, i, j+1, k+1, visited) || existHelper(board, word, i-1, j, k+1, visited) || existHelper(board, word, i, j-1, k+1, visited);
        visited[i][j]=false;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(existHelper(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};