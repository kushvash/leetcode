class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0, right=0, n=nums.size();

        while(right<n) {
            int count=1;

            while(right+1<n && nums[right]==nums[right+1]) {
                right++;
                count++;
            }

            for(int i=0; i<min(count, 2); i++) {
                nums[left]=nums[right];
                left++;
            }

            right++;
        }

        return left;
    }
};

// [1,1,1,1,2,2,2,3]