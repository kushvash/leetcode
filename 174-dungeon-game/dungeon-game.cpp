class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // need[i][j] = min HP required on entry to (i,j) so that
        // moving only right/down you can reach the princess alive.
        // We size (m+1)x(n+1) and pad the “extra” row/col with INF.
        vector<vector<int>> need(m+1, vector<int>(n+1, INT_MAX));
        // Base case: beyond the princess’s cell, you need 1 HP to “enter” the padding.
        need[m][n-1] = 1;
        need[m-1][n] = 1;

        // Fill from bottom–right back to top–left
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                // Choose the cheaper next step (down or right)
                int bestNext = min(need[i+1][j], need[i][j+1]);
                // If dungeon[i][j] is negative, you lose HP; positive you gain.
                // You must have at least 1 HP after the room’s effect:
                need[i][j] = max(1, bestNext - dungeon[i][j]);
            }
        }

        return need[0][0];
    }
};