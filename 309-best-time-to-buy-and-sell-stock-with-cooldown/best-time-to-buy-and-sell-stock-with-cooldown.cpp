class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // dp[i][0] = best profit ending day i holding a share
        // dp[i][1] = best profit ending day i free to buy (no share)
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0]=-prices[0];
        dp[0][1]=0;

        for(int i=1; i<n; i++){
            int buyingProfit;

            if(i>=2){
                buyingProfit=dp[i-2][1]-prices[i];
            }else{
                buyingProfit=-prices[i];
            }

            dp[i][0]=max(dp[i-1][0], buyingProfit);
            dp[i][1]=max(dp[i-1][0]+prices[i], dp[i-1][1]);
        }

        return dp[n-1][1];
    }
};