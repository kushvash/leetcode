class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int start, vector<int>& currSet, int target, vector<vector<int>>& res){
        if(target==0){
            res.push_back(currSet);
            return;
        }
        if(target<0 || start==candidates.size()){
            return;
        }

        //excluding element
        // int i=start;
        // while(i<candidates.size() && (i==start || candidates[i]==candidates[i-1])){
        //     i++;
        // }
        // combinationSumHelper(candidates, i, currSet, target, res);
        

        // //including element
        // currSet.push_back(candidates[start]);
        // combinationSumHelper(candidates, start+1, currSet, target-candidates[start], res);
        // currSet.pop_back();


        for(int i=start; i<candidates.size(); i++){
            if(i!=start && candidates[i]==candidates[i-1]){
                continue;
            }
            currSet.push_back(candidates[i]);
            combinationSumHelper(candidates, i+1, currSet, target-candidates[i], res);
            currSet.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> currSet;
        combinationSumHelper(candidates, 0, currSet, target, res);

        return res;

    }
};