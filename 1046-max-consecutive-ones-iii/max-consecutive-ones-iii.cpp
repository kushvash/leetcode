class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount=0, left=0, res=0, n=nums.size();

        for(int right=0; right<n; right++) {
            if(nums[right]==0) {
                zeroCount++;
            }

            while(zeroCount>k) {
                if(nums[left]==0) {
                    zeroCount--;
                }
                left++;
            }

            res=max(res, right-left+1);
        }

        return res;
    }
};