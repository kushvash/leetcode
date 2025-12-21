class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1, n=nums.size();

        for(int right=1; right<n; right++) {
            if(nums[right]!=nums[right-1]) {
                nums[left]=nums[right];
                left++;
            }
        }

        return left;
    }
};