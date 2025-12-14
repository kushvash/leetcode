class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});

        for(int i=1; i<numRows; i++) {
            int prev=0;
            vector<int> curr;

            for(int j=0; j<i; j++) {
                curr.push_back(res[i-1][j]+prev);
                prev=res[i-1][j];
            }

            curr.push_back(1);

            res.push_back(curr);
        }

        return res;
    }
};