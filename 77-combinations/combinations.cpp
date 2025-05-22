class Solution {
public:
    void combineHelper(int& n, int& k, int currNum, vector<int>& currSet, vector<vector<int>>& res) {
        if(currSet.size()==k) {
            res.push_back(currSet);
            return;
        }
        if(currSet.size()>k || currNum>n) {
            return;
        }

        // excluding currNum
        combineHelper(n, k, currNum+1, currSet, res);
        // including currNum
        currSet.push_back(currNum);
        combineHelper(n, k, currNum+1, currSet, res);
        currSet.pop_back();


        // for(int i=currNum; i<=n; i++) {
        //     currSet.push_back(i);
        //     combineHelper(n, k, i+1, currSet, res);
        //     currSet.pop_back();
        // }


        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> currSet; 
        vector<vector<int>> res;

        combineHelper(n, k, 1, currSet, res);

        return res;
    }
};