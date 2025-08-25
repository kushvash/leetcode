class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(nums, ans, 0, curr);

        return ans;

    }

    void subsetsWithDupHelper(vector<int>& nums, vector<vector<int>>& res, int i, vector<int>& curr){
        if(i==nums.size()){
            res.push_back(curr);
            return;
        }

        // including nums[i]
        curr.push_back(nums[i]);
        subsetsWithDupHelper(nums, res, i+1, curr);
        curr.pop_back();

        // excluding nums[i]
        i++;
        while(i<nums.size() && nums[i]==nums[i-1]){
            i++;
        }

        subsetsWithDupHelper(nums, res, i, curr);

        return;
    }
};