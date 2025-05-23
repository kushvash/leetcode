class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1, mid;

        while(lo<hi){
            mid=lo+(hi-lo)/2;

            if(nums[mid]>=target) {
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        if(nums[lo]==target){
            return lo;
        }

        return -1;


    }
};