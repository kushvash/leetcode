class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        vector<vector<int>> dp(n+1, vector<int> (4005, 0));

        dp[n][2000] = 1;

        // for(int i=-1000; i<=1000; i++){        
        //     if(i==nums[n-1]){
        //         dp[n-1][i+2000]+=1;
        //     }
        //     if(i==-nums[n-1]){
        //         dp[n-1][i+2000]+=1;
        //     }
        // }
    
        for(int i=n-1; i>=0; i--){
            for(int j=-1000; j<=1000; j++){
                dp[i][j+2000]+=dp[i+1][j-nums[i]+2000];
                dp[i][j+2000]+=dp[i+1][j+nums[i]+2000];
            }
        }

        return dp[0][target+2000];
    }
};