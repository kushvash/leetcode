class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1), right(nums.size(), 1), ans(nums.size(), 1);
        
        int curr=1;

        for(int i=0; i<nums.size(); i++) {
            left[i]=curr;
            curr*=nums[i];
        }

        curr=1;

        for(int i=nums.size()-1; i>=0; i--) {
            right[i]=curr;
            curr*=nums[i];
        }


        for(int i=0; i<nums.size(); i++) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};