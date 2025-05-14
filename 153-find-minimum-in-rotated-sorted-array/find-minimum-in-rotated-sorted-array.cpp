class Solution {
public:
    int findMin(vector<int>& nums) {
        int target=nums[0], lo=0, hi=nums.size()-1, mid;

        while(lo<hi){
            mid=lo+(hi-lo)/2;

            if(nums[mid]<target){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        return min(nums[lo], nums[0]);
    }
};