class Solution {
public:
    string longestPalindrome(string s) {
        string sNew=s;
        reverse(sNew.begin(), sNew.end());

        int n1=s.size(), n2=sNew.size();

        if(n1<2){
            return s;
        }

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        int maxLen = 0;
        int endIdx = 0;

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s[i-1]==sNew[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }

                int startInS   = i - dp[i][j];
                int startInSrc = n1 - j;  

                if (startInS == startInSrc && dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIdx = i - 1;
                }
            }
        }

        return s.substr(endIdx - maxLen + 1, maxLen);
    }
};