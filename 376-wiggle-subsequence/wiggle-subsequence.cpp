class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size(), maxL=1;

        vector<int> dpP(n, 1), dpN(n, 1);

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    dpP[i]=max(dpP[i], 1+dpN[j]);
                }else if(nums[i]<nums[j]){
                    dpN[i]=max(dpN[i], 1+dpP[j]);
                }
            }

            maxL=max(maxL, max(dpP[i], dpN[i]));
        }

        return maxL;
    }
};