class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, vector<int>& currSet, int start, int target, vector<vector<int>>& res) {
        if(target==0){
            res.push_back(currSet);
            return;
        }
        if(start==candidates.size() || target<0){
            return;
        }

        // including curr element
        currSet.push_back(candidates[start]);
        combinationSumHelper(candidates, currSet, start, target-candidates[start], res);
        currSet.pop_back();
        
        // excluding curr element
        combinationSumHelper(candidates, currSet, start+1, target, res);
        
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currSet;
        vector<vector<int>> res;

        combinationSumHelper(candidates, currSet, 0, target, res);

        return res;

    }
};