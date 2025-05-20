class Solution {
public:    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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

        vector<vector<int>> temp, ans;
        
        for(int i=start; i<candidates.size(); i++){
            if(candidates[i]>target){
                break;
            }

            temp=combinationSumHelper(candidates, i, target-candidates[i]);

            for(auto j: temp){
                j.push_back(candidates[i]);
                ans.push_back(j);
            }

        }

        return ans;
    }
};