class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), maxS=nums[0];
        vector<int> dp(n, 0);   
        dp[0]=nums[0];

        for(int i=1; i<n; i++){
            dp[i]=max(nums[i], dp[i-1]+nums[i]);
            maxS=max(maxS, dp[i]);
        } 

        return maxS;


    }
};