class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0, right=0, currSum=0, res=INT_MIN;
        
        while(right<nums.size()) {
            currSum+=nums[right];
            right++;

            if(right-left>k) {
                currSum-=nums[left];
                left++;
            }

            if(right-left==k) {
                res=max(res, currSum);
            }
        }

        return (double)res/k;
    }
};