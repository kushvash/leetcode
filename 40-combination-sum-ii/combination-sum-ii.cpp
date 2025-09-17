class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, int target, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(target==0) {
            res.push_back(curr);
            return;
        }if(target<0 || i==candidates.size()) {
            return;
        }

        // including candidates[i]
        curr.push_back(candidates[i]);
        combinationSum2Helper(candidates, target-candidates[i], i+1, curr, res);
        curr.pop_back();

        // excluding candidates[i]
        int j;
        for(j=i+1; j<candidates.size(); j++) {
            if(candidates[j]!=candidates[j-1]) {
                break;
            }
        }

        combinationSum2Helper(candidates, target, j, curr, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> res;

        combinationSum2Helper(candidates, target, 0, curr, res);
    
        return res;
    }
};