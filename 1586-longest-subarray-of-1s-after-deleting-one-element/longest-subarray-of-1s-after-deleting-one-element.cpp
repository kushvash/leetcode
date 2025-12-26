class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount=0, left=0, res=0, n=nums.size();

        for(int right=0; right<n; right++) {
            if(nums[right]==0) {
                zeroCount++;
            }

            while(zeroCount>1) {
                if(nums[left]==0) {
                    zeroCount--;
                }
                left++;
            }
            
            if(zeroCount==1) {
                res=max(res, right-left);
            }else {
                res=max(res, right-left+1);
            }
        }

        if(zeroCount==0) {
            return res-1;
        }

        return res;
    }
};