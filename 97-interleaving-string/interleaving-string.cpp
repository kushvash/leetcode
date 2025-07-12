class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != (int)s3.size()) 
            return false;

        // dp[i][j] = can s3[0..i+j-1] be formed by interleaving
        //            s1[0..i-1] and s2[0..j-1]
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        // fill first column (only from s1)
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        // fill first row (only from s2)
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        // fill the rest
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // take next char from s1
                if (dp[i-1][j] && s1[i-1] == s3[i+j-1])
                    dp[i][j] = true;
                // or take next char from s2
                if (dp[i][j-1] && s2[j-1] == s3[i+j-1])
                    dp[i][j] = true;
            }
        }

        return dp[m][n];
    }
};