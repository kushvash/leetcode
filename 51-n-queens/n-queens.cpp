class Solution {
public:
    bool checkSafety(int n, int i, int j, vector<bool>& safeRow, vector<bool>& safeCol, vector<bool>& safeD1, vector<bool>& safeD2) {
        if(safeRow[i] || safeCol[j]){
            return false;
        }

        if(safeD1[i-j+n-1] || safeD2[i+j]){
            return false;
        }

        return true;
    }

    

    void solveNQueensHelper(int n, int i, vector<vector<char>>& currSet, vector<bool>& safeRow, vector<bool>& safeCol, vector<bool>& safeD1, vector<bool>& safeD2, vector<vector<string>>& res) {
        // base case
        if(n==i){
            vector<string> temp;

            for(vector<char> v: currSet) {
                string tempS;
                for(char c: v) {
                    tempS.push_back(c);
                }
                temp.push_back(tempS);
            }

            res.push_back(temp);
        }


        // for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(checkSafety(n, i, j, safeRow, safeCol, safeD1, safeD2)){
                    safeRow[i]=true;
                    safeCol[j]=true;
                    safeD1[i-j+n-1]=true;
                    safeD2[i+j]=true;

                    currSet[i][j]='Q';

                    solveNQueensHelper(n, i+1, currSet, safeRow, safeCol, safeD1, safeD2, res);

                    safeRow[i]=false;
                    safeCol[j]=false;
                    safeD1[i-j+n-1]=false;
                    safeD2[i+j]=false;

                    currSet[i][j]='.';
                }
            // }
        }


    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> currSet(n, vector<char> (n, '.'));
        
        vector<bool> safeRow(n, false); 
        vector<bool> safeCol(n, false); 
        vector<bool> safeD1(2*n-1, false); 
        vector<bool> safeD2(2*n-1, false);

        vector<vector<string>> res;

        solveNQueensHelper(n, 0, currSet, safeRow, safeCol, safeD1, safeD2, res);


        return res;
    }
};