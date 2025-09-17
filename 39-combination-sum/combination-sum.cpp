class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int target, int i, vector<int>& curr, int currSum, vector<vector<int>>& res) {
        if(currSum==target) {
            res.push_back(curr);
            return;
        }if(currSum>target || i==candidates.size()) {
            return;
        }

        // Not adding i
        combinationSumHelper(candidates, target, i+1, curr, currSum, res);

        // Adding the i
        curr.push_back(candidates[i]);
        combinationSumHelper(candidates, target, i, curr, currSum+candidates[i], res);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;

        combinationSumHelper(candidates, target, 0, curr, 0, res);

        return res;
    }
};