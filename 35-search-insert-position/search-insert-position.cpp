class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        if(target<nums[0]){
            return 0;
        }
        
        int lo=0, hi=nums.size()-1, mid;



        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(nums[mid]>=target){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        return lo;
    }
};