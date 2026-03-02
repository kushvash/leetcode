class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), left=0, right=0;

        while(right<n) {
            int count=1;

            while(right<n-1 && nums[right+1]==nums[right]) {
                count++;
                right++;
            }

            for(int i=0; i<min(2, count); i++) {
                nums[left]=nums[right];
                left++;
            }

            right++;
        }

        return left;
    }
};