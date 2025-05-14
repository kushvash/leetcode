class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1, mid;

        if(nums.size()==0){
            return {-1,-1};
        }
        
        while(lo<=hi){
            mid=lo+(hi-lo)/2;

            if(nums[mid]>=target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        if(lo==nums.size() || nums[lo]!=target){
            return {-1,-1};
        }

        vector<int> ans;
        ans.push_back(lo);

        lo=0;
        hi=nums.size()-1;


        while(lo<=hi){
            mid=lo+(hi-lo)/2;

            if(nums[mid]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        ans.push_back(hi);

        return ans;
    }
};