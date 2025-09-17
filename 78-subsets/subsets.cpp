class Solution {
public:
    void subsetsHelper(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(i==nums.size()) {
            res.push_back(curr);
            return;
        }

        subsetsHelper(nums, i+1, curr, res);
        curr.push_back(nums[i]);
        subsetsHelper(nums, i+1, curr, res);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        subsetsHelper(nums, 0, curr, res);

        return res;    
    }
};