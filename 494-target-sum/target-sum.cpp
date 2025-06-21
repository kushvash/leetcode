class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        // for(int num:nums){
        //     maxS+=num;
        // }

        vector<vector<int>> dp(n, vector<int> (4005, 0));

        for(int i=-1000; i<=1000; i++){        
            if(i==nums[n-1]){
                dp[n-1][i+2000]+=1;
            }
            if(i==-nums[n-1]){
                dp[n-1][i+2000]+=1;
            }
        }
    
        for(int i=n-2; i>=0; i--){
            for(int j=-1000; j<=1000; j++){
                dp[i][j+2000]+=dp[i+1][j-nums[i]+2000];
                dp[i][j+2000]+=dp[i+1][j+nums[i]+2000];
                
            }
        }

        return dp[0][target+2000];
    }
};