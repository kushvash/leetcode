class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> helper;
        int k;

        for(int i=0; i<nums.size(); i++) {
            k=target-nums[i];
            if(helper.find(k)!=helper.end()) {
                return {helper[k], i};
            }
            helper[nums[i]]=i;
        }

        return {-1, -1};
    }
};