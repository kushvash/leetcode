class Solution {
public:
    void solveNQueensHelper(int n, int i, vector<string>& currSet, vector<bool>& safeCol, vector<bool>& safeD1, vector<bool>& safeD2, vector<vector<string>>& res) {
        // base case
        if(n==i) {
            res.push_back(currSet);

            return;
        }

        // recursive step
        for(int j=0; j<n; j++) {

            int d1 = i - j + n - 1, d2 = i + j;

            if (safeCol[j] || safeD1[d1] || safeD2[d2]) 
                continue;
        
            safeCol[j]=true;
            safeD1[i-j+n-1]=true;
            safeD2[i+j]=true;

            currSet[i][j]='Q';

            solveNQueensHelper(n, i+1, currSet, safeCol, safeD1, safeD2, res);

            safeCol[j]=false;
            safeD1[i-j+n-1]=false;
            safeD2[i+j]=false;

            currSet[i][j]='.';
            
        }


    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> currSet(n, string(n,'.'));

        vector<bool> safeCol(n, false); 
        vector<bool> safeD1(2*n-1, false); 
        vector<bool> safeD2(2*n-1, false);

        vector<vector<string>> res;

        solveNQueensHelper(n, 0, currSet, safeCol, safeD1, safeD2, res);


        return res;
    }
};