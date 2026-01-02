class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res=0, l=0, r=0, sum=0, n=nums.size(), prefixZ=0;

        while(r<n) {
            sum+=nums[r];

            while(l<r && (nums[l]==0 || sum>goal)) {
                if(nums[l]==1) {
                    sum--;
                    prefixZ=0;
                }else {
                    prefixZ++;
                }   

                l++;
            }

            if(sum==goal) {
                res+=prefixZ;
                res++;
            }

            r++;
        }

        return res;
    }
};