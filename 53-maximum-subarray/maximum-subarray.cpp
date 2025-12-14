class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0], currSum=nums[0], n=nums.size();

        for(int i=1; i<n; i++) {
            currSum=max(nums[i], currSum+nums[i]);
            res=max(res, currSum);
        }

        return res;
    }
};