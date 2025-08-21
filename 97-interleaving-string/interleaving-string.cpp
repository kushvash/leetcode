class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();

        // If lengths don't add up, it's impossible
        if (m + n != (int)s3.size()) return false;

        // dp[i][j] = true if s3[0...(i+j-1)] can be formed 
        // by interleaving s1[0...(i-1)] and s2[0...(j-1)]
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // Base case: empty s1 and s2 form empty s3
        dp[0][0] = true;

        // Fill first column: can only come from s1
        for (int i = 1; i <= m; i++){
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        // Fill first row: can only come from s2
        for (int j = 1; j <= n; j++){
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        // Fill the rest of the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Option 1: last char came from s1
                bool fromS1 = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                
                // Option 2: last char came from s2
                bool fromS2 = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);

                dp[i][j] = fromS1 || fromS2;
            }
        }

        // Answer is whether full s1 and s2 can form s3
        return dp[m][n];
    }
};