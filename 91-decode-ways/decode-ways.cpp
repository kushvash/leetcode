class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 1; i < n; ++i) {
            int ways = 0;

            // single digit s[i]
            if (s[i] != '0') {
                ways += dp[i-1];
            }

            // two digits s[i-1..i]
            int two = (s[i-1]-'0')*10 + (s[i]-'0');
            if (two >= 10 && two <= 26) {
                if(i>=2) {
                    ways+=dp[i-2];       
                }else {
                    ways+=1;
                }
            }

            dp[i] = ways;
        }
        return dp[n-1];
    }
};