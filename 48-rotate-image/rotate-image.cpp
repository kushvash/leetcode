class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top=0, bottom=matrix.size()-1;

        while(top<bottom) {
            int left=top;
            int right=bottom;
            
            for(int i=0; i<right-left; i++) {
                int firstEle=matrix[top][left+i];

                matrix[top][left+i]=matrix[bottom-i][left];

                matrix[bottom-i][left]=matrix[bottom][right-i];

                matrix[bottom][right-i]=matrix[top+i][right];

                matrix[top+i][right]=firstEle;
            }

            top++;
            bottom--;
        }

        return;
    }
};