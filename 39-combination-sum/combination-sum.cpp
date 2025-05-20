class Solution {
public:    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSumHelper(candidates, 0, target);
    }

    vector<vector<int>> combinationSumHelper(vector<int> candidates, int start, int target) {
        if(target==0){
            //return positive
            return {{}};
        }else if(target<0 || start==candidates.size()){
            //return negative
            return {};
        }

        vector<vector<int>> ans1, ans2, ans;
        
        //including current element
        ans1 = combinationSumHelper(candidates, start, target-candidates[start]);

        for(int i=0; i<ans1.size(); i++){
            ans1[i].push_back(candidates[start]);
        }

        //excluding current element
        ans2 = combinationSumHelper(candidates, start+1, target);
        
        for(int i=0; i<ans1.size(); i++){
            ans.push_back(ans1[i]);
        }

        for(int i=0; i<ans2.size(); i++){
            ans.push_back(ans2[i]);
        }

        return ans;
    }
};