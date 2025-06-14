class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<bool>& record, vector<int>& curr, vector<vector<int>>& res) {
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!record[i]){
                record[i]=true;
                curr.push_back(nums[i]);
                permuteHelper(nums, record, curr, res);
                record[i]=false;
                curr.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> record(nums.size(), false);
        vector<int> curr;

        permuteHelper(nums, record, curr, res);

        return res;
    }
};