class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=nums[0], res=nums[0], n=nums.size();
        
        for(int i=1; i<n; i++) {
            currSum=max(currSum+nums[i], nums[i]);

            res=max(currSum, res);
        }

        return res;
    }
};