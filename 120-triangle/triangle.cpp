class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), n;
        
        if(m==1){
            return triangle[0][0];
        }

        n=triangle[m-1].size();

        vector<vector<int>> dp(m);
        dp[0].push_back(triangle[0][0]);


        for(int i=1; i<m; i++){
            dp[i].push_back(triangle[i][0]+dp[i-1][0]);
            for(int j=1; j<i; j++){
                {
                    dp[i].push_back(triangle[i][j]+min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
            dp[i].push_back(triangle[i][i]+dp[i-1][i-1]);
        }


        int ans=INT_MAX;

        for(int i=0; i<n; i++){
            ans=min(ans, dp[m-1][i]);
        }

        return ans;
    }
};