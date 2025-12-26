class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0, n=nums.size(), left=0, res=n+1;

        for(int right=0; right<n; right++) {
            sum+=nums[right];
            
            while(sum>=target) {
                res=min(res, right-left+1);        
                sum-=nums[left];
                left++;
            }
        }
        if(res==n+1) {
            return 0;
        }
        
        return res;
    }
};