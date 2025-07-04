class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(), total=0;


        for(int num: nums){
            total+=num;
        }

        target+=total;

        if(target%2!=0 || target<0){
            return 0;
        }

        target/=2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        dp[0][0]=1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=target; j++){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }


        return dp[n][target];
    }
};