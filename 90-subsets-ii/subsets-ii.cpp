class Solution {
public:
    void subsetsWithDupHelper(vector<int>& nums, vector<int> currSet , int start, vector<vector<int>>& res) {
        // base case
        if(start==nums.size()) {
            res.push_back(currSet);
            return;
        }

        // excluding current
        int i=start+1;

        while(i<nums.size() && nums[i]==nums[i-1]){
            i++;
        }

        subsetsWithDupHelper(nums, currSet, i, res);

        // including current
        currSet.push_back(nums[start]);

        subsetsWithDupHelper(nums, currSet, start+1, res);

        currSet.pop_back();

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        subsetsWithDupHelper(nums, {}, 0, res);

        return res;
    }
};