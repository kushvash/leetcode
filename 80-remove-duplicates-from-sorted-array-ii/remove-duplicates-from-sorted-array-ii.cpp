class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0, right=0, n=nums.size();

        while(right<n) {
            int count=1;

            while(right+1<n && nums[right]==nums[right+1]) {
                count++;
                right++;
            }

            count=min(count, 2);

            while(count--) {
                nums[left]=nums[right];
                left++;
            }

            right++;
        }

        return left;
    }
};