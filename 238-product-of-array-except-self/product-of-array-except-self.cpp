class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftP(n, 1);
        vector<int> rightP(n, 1);

        for(int i=1; i<n; i++) {
            leftP[i]=leftP[i-1]*nums[i-1];
            rightP[n-1-i]=rightP[n-i]*nums[n-i];
        }

        for(int i=0; i<n; i++) {
            leftP[i]*=rightP[i];
        }

        return leftP;
    }
};