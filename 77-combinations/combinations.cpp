class Solution {
public:
    void combineHelper(int n, int k, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(curr.size()==k) {
            res.push_back(curr);
            return;
        }
        if(i>n) {
            return;
        }

        // using the current element
        curr.push_back(i);
        combineHelper(n, k, i+1, curr, res);
        curr.pop_back();

        // not using the current element
        combineHelper(n, k, i+1, curr, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> res;

        combineHelper(n, k, 1, curr, res);

        return res;
    }
};