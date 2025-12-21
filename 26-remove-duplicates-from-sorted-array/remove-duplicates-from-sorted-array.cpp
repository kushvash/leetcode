class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0, n=nums.size();

        unordered_set<int> record;

        for(int right=0; right<n; right++) {
            if(record.find(nums[right])==record.end()) {
                nums[left]=nums[right];
                left++;
                record.insert(nums[right]);
            }
        }

        return left;
    }
};