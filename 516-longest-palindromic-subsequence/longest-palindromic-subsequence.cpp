class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string sNew=s, ans="";
        int n=s.size();

        if(n==1){
            return 1;
        }

        reverse(sNew.begin(), sNew.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));


        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==sNew[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];

        // int i=n, j=n;

        // while(i>0 && j>0){
        //     if(s[i-1]==sNew[j-1]){
        //         ans+=s[i-1];
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1]){
        //         i--;
        //     }else{
        //         j--;
        //     }
        // }


        // reverse(ans.begin(), ans.end());

        // return ans.size();
    }
};