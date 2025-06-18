class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(), maxL=0;

        vector<unordered_map<int, int>> dp(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int diff=nums[i]-nums[j];
                if(dp[j][diff]>0){
                    dp[i][diff]=1+dp[j][diff];
                }else{
                    dp[i][diff]=2;
                }

                maxL=max(maxL, dp[i][diff]);
            }
        }

        return maxL;
    }
};