class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int p=0;

        while(p<nums.size()){
            if(nums[p]!=p && nums[p]<nums.size()){
                swap(nums[p], nums[nums[p]]);
            }else{
                p++;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i){
                return i;
            }
        }

        return nums.size();
    }
};