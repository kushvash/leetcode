class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size(), cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 'X' && (i == 0 || b[i-1][j] != 'X') && (j == 0 || b[i][j-1] != 'X')) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};