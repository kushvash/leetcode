class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), maxP=nums[0];
        vector<int> dpMin(n, 0), dpMax(n, 0);

        dpMin[0]=dpMax[0]=nums[0];
        
        for(int i=1; i<n; i++){
            dpMax[i]=max(nums[i], max(dpMax[i-1]* nums[i], dpMin[i-1]* nums[i]));

            dpMin[i]=min(nums[i], min(dpMax[i-1]* nums[i], dpMin[i-1]* nums[i]));

            maxP=max(dpMax[i], maxP);
        }

        return maxP;
    }
};