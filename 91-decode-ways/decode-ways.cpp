class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;               // empty prefix
        dp[1] = 1;               // first char is non-zero

        for (int i = 2; i <= n; ++i) {
            // single digit s[i-1]
            if (s[i-1] != '0')
                dp[i] += dp[i-1];

            // two digits s[i-2..i-1]
            int two = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (two >= 10 && two <= 26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};