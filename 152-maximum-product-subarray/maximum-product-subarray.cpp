class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpMin(nums.size());
        vector<int> dpMax(nums.size());
        
        dpMin[0]=nums[0];
        dpMax[0]=nums[0];

        int res=nums[0];

        for(int i=1; i<nums.size(); i++){
            dpMax[i]=max(max(dpMin[i-1]*nums[i], dpMax[i-1]*nums[i]), nums[i]);
            dpMin[i]=min(min(dpMin[i-1]*nums[i], dpMax[i-1]*nums[i]), nums[i]);

            res = max(res, dpMax[i]);
        }


        return res;
    }
};