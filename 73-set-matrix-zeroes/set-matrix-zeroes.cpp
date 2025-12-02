class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS=matrix.size(), COLS=matrix[0].size();
        bool isCol=false;

        for(int row=0; row<ROWS; row++) {
            if(matrix[row][0]==0) {
                isCol=true;
            }
            for(int col=1; col<COLS; col++) {
                if(matrix[row][col]==0) {
                    matrix[row][0]=0;
                    matrix[0][col]=0;
                }
            }
        }

        for(int row=1; row<ROWS; row++) {
            for(int col=1; col<COLS; col++) {
                if(matrix[row][0]==0 || matrix[0][col]==0) {
                    matrix[row][col]=0;
                }
            }
        }

        if(matrix[0][0]==0) {
            for(int col=0; col<COLS; col++) {
                matrix[0][col]=0;
            }
        }

        if(isCol) {
            for(int row=0; row<ROWS; row++) {
                matrix[row][0]=0;
            }
        }
    }
};