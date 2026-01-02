class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) {
            return 0;
        }

        int res=0, pro=1, l=0, r=0, n=nums.size();

        while(r<n) {
            pro*=nums[r];

            while(pro>=k) {
                pro/=nums[l];
                l++;
            }

            res+=r-l+1;
            r++;
        }

        return res;
    }
};