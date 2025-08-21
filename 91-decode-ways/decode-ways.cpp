class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(n, 0);
        dp[0] = 1;  // first char is non-zero

        for (int i = 1; i < n; i++) {
            int ways = 0;

            // single digit s[i]
            if (s[i] != '0') {
                ways += dp[i-1];
            }

            // two digits s[i-1..i]
            int two = (s[i-1]-'0')*10 + (s[i]-'0');
            if (two >= 10 && two <= 26) {
                ways += (i >= 2 ? dp[i-2] : 1); // empty prefix counts as 1
            }

            dp[i] = ways;
        }

        return dp[n-1];
    }
};