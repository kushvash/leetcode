class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), res=n+1, currSum=0, l=0, r=0;

        while(r<n) {
            currSum+=nums[r];

            while(currSum>=target) {
                res=min(res, r-l+1);
                currSum-=nums[l];
                l++;
            }

            r++;
        }

        if(res==n+1) {
            return 0;
        }

        return res;
    }
};