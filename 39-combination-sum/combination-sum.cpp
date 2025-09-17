class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int target, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(target==0) {
            res.push_back(curr);
            return;
        }if(target<0 || i==candidates.size()) {
            return;
        }

        // Not adding i
        combinationSumHelper(candidates, target, i+1, curr, res);

        // Adding the i
        curr.push_back(candidates[i]);
        combinationSumHelper(candidates, target-candidates[i], i, curr, res);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;

        combinationSumHelper(candidates, target, 0, curr, res);

        return res;
    }
};