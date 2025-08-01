class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=1; i<=m; i++){
            dp[i][0]=i;
        }

        for(int j=1; j<=n; j++){
            dp[0][j]=j;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int i1, i2, i3;
                    i1=dp[i-1][j];
                    i2=dp[i][j-1];
                    i3=dp[i-1][j-1];

                    dp[i][j]=1+min(i1, min(i2, i3));
                }
            }
        }

        return dp[m][n];
    }
};