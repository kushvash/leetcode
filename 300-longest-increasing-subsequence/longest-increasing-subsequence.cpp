class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), maxG=1;

        vector<int> dp(n, 1);

        for(int i=1; i<n; i++){
            int maxL=1;

            for(int j=i-1; j>=0; j--){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }

            maxG=max(maxG, dp[i]);
        }


        return maxG;
    }
};