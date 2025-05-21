class Solution {
public:
    void subsetsHelper(vector<int>& nums, vector<int>& currSet , int start, vector<vector<int>>& res) {
        // base case
        if(start==nums.size()) {
            res.push_back(currSet);
            return;
        }

        // excluding current
        subsetsHelper(nums, currSet, start+1, res);

        // including current
        currSet.push_back(nums[start]);

        subsetsHelper(nums, currSet, start+1, res);

        currSet.pop_back();

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> currSet;

        subsetsHelper(nums, currSet, 0, res);

        return res;
    }
};