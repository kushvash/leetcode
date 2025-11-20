class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> record;

        int n=nums.size(), k=0;

        for(int i=0; i<n; i++) {
            if(record.find(nums[i])==record.end()) {
                record.insert(nums[i]);
                nums[k]=nums[i];
                k++;        
            }
        }

        return k;
    }
};