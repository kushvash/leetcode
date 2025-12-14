class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN, left=0, right=0, currSum=0, n=nums.size();

        while(right<n) {
            currSum+=nums[right];
            right++;
            
            res=max(res, currSum);

            while(left<right && currSum<0) {
                currSum-=nums[left];
                left++;
            }
        }

        return res;
    }
};