class Solution {
public:
    void subsetsWithDupHelper(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(i==nums.size()) {
            res.push_back(curr);
            return;
        }

        // including nums[i]
        curr.push_back(nums[i]);
        subsetsWithDupHelper(nums, i+1, curr, res);
        curr.pop_back();

        // excluding nums[i]
        int j;
        for(j=i+1; j<nums.size(); j++) {
            if(nums[j]!=nums[j-1]) {
                break;
            }
        }

        subsetsWithDupHelper(nums, j, curr, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> res;

        subsetsWithDupHelper(nums, 0, curr, res);

        return res;
    }
};