class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(), maxS=0;

        for(int num: nums){
            maxS+=num;
        }
        target+=maxS;

        if(target%2!=0 || target<0){
            return 0;
        }

        target/=2;
        
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

        dp[0][0]=1;

        for(int i=1; i<=n; i++){
            for(int s=0; s<=target; s++){
                dp[i][s]+=dp[i-1][s];
                if(s>=nums[i-1]){
                    dp[i][s]+=dp[i-1][s-nums[i-1]];
                }
            }
        }

        return dp[n][target];
    }
};