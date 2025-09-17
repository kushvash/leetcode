class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<bool>& record, vector<int>& curr, vector<vector<int>>& res) {
        if(curr.size()==nums.size()) {
            res.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(record[i]) {
                continue;
            }

            record[i]=true;
            curr.push_back(nums[i]);
            permuteHelper(nums, record, curr, res);
            curr.pop_back();
            record[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> record(nums.size(), false); 
        vector<int> curr; 
        vector<vector<int>> res;

        permuteHelper(nums, record, curr, res);

        return res;
    }
};