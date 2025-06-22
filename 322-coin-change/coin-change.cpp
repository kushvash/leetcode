class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int INF = INT_MAX/2; 
        
        vector<vector<int>> dp(n+1, vector<int> (amount+1, INF));

        for(int i=1; i<=n; i++){
            dp[i][0]=0;
        }


        for(int c=1; c<=n; c++){
            for(int s=1; s<=amount; s++){
                if(s>=coins[c-1]){
                    dp[c][s]=min(dp[c-1][s], 1+dp[c][s-coins[c-1]]);
                }else{
                    dp[c][s]=dp[c-1][s];
                }
            }
        }
        if(dp[n][amount]<INF){
            return dp[n][amount];
        }
        return -1;
    }
};