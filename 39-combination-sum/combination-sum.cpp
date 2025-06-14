class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int target, int currentElement, int currSum, vector<int>& curr, vector<vector<int>>& res) {
        if(currSum==target){
            res.push_back(curr);
            return;
        }
        if(currSum>target || currentElement==candidates.size()){
            return;
        }

        // Excluding current element
        currentElement++;
        combinationSumHelper(candidates, target, currentElement, currSum, curr, res);
        currentElement--;

        // Including current element
        curr.push_back(candidates[currentElement]);
        currSum+=candidates[currentElement];
        combinationSumHelper(candidates, target, currentElement, currSum, curr, res);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        
        combinationSumHelper(candidates, target, 0, 0, curr, res);

        return res;
    }
};