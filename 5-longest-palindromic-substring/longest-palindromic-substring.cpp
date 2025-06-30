class Solution {
public:
    string longestPalindrome(string s) {
        string sNew=s, ans="";
        int n=s.size();

        int maxLen = 0, endIdx = 0;


        if(n==1){
            return s;
        }

        reverse(sNew.begin(), sNew.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));


        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==sNew[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];

                    if (dp[i][j] > maxLen && (i - dp[i][j]) == (n - j)) {
                        maxLen = dp[i][j];
                        endIdx = i - 1;
                    }
                }
            }
        }

        return s.substr(endIdx - maxLen + 1, maxLen);

    }
};