class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return true;
        }

        vector<bool> dp(n, false);

        dp[0]=true;

        for(int i=0; i<n; i++){
            if(!dp[i]){
                break;
            }
            for(int j=1; j<=nums[i]; j++){
                // if(i+j>=n){
                //     break;
                // }
                if(i+j==n-1){
                    return true;
                }
                dp[i+j]=true;
            }
        }

        return false;
    }
};