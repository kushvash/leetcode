class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0, n=nums.size();

        for(int i=0; i<n; i++){
            ans^=i;
            ans^=nums[i];
        }

        ans^=n;

        return ans;
    }
};