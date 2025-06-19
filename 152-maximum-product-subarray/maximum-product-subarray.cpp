class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), maxP=nums[0];
                
        if(n==1){
            return nums[0];
        }

        vector<int> minDP(n, 0);
        vector<int> maxDP(n, 0);
    
        minDP[0]=maxDP[0]=nums[0];

        for(int i=1; i<n; i++){
            maxDP[i]=max(nums[i], max(nums[i] * minDP[i-1], nums[i] * maxDP[i-1]));
            minDP[i]=min(nums[i], min(nums[i] * minDP[i-1], nums[i] * maxDP[i-1]));

            maxP=max(maxP, maxDP[i]);
        }

        return maxP;
        
    }
};