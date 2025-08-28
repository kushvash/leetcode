class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<bool>& used, vector<int> curr, vector<vector<int>>& res) {
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!used[i]){
                curr.push_back(nums[i]);
                used[i]=true;
                permuteHelper(nums, used, curr, res);
                curr.pop_back();
                used[i]=false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false); 
        vector<int> curr;
        vector<vector<int>> res;

        permuteHelper(nums, used, curr, res);

        return res;
    }
};