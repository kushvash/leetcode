class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1, mid;

        while(lo<hi) {
            mid=lo+(hi-lo+1)/2;

            if(nums[mid]>target) {
                hi=mid-1;
            }else {
                lo=mid;
            }
        }

        if(nums.size()==0 || nums[lo]!=target){
            return {-1, -1};
        }

        int resEnd=lo;

        lo=0;
        hi=nums.size()-1;

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(nums[mid]>=target) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        return {lo, resEnd};
    }
};