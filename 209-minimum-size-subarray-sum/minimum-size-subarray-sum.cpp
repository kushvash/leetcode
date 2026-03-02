class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), left=0, res=INT_MAX, sum=0;

        for(int right=0; right<n; right++) {
            sum+=nums[right];

            while(sum>=target && left<=right) {
                res=min(res, right-left+1);
                sum-=nums[left];
                left++;
            }
        }

        if(res==INT_MAX) {
            return 0;
        }

        return res;
    }
};