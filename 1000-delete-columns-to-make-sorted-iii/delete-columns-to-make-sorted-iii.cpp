class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = (int)strs.size();
        int n = (int)strs[0].size();

        vector<int> dp(n, 1); 
        int best = 1;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                bool ok = true;
                for (int r = 0; r < m; ++r) {
                    if (strs[r][i] > strs[r][j]) { 
                        ok = false;
                        break;
                    }
                }
                if (ok) dp[j] = max(dp[j], dp[i] + 1);
            }
            best = max(best, dp[j]);
        }

        return n - best;
    }
};