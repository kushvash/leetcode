class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& res, vector<int> currSet) {
        if(currSet.size()==nums.size()){
            res.push_back(currSet);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                visited[i]=true;
                currSet.push_back(nums[i]);

                permuteHelper(nums, visited, res, currSet);

                visited[i]=false;
                currSet.pop_back();
            }
        }

        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> res;

        permuteHelper(nums, visited, res, {});

        return res;
    }
};