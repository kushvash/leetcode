class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top, left, right, bottom, count=0, m=matrix.size(), n=matrix[0].size();
        top=0;
        left=0;
        bottom=m-1;
        right=n-1;
        vector<int> res;

        while(count<m*n){
            // path 1
            for(int i=left; i<=right; i++){
                count++;
                res.push_back(matrix[top][i]);
            }
            if(count==m*n){
                break;
            }

            top++;
    
            // path 2        
            for(int i=top; i<=bottom; i++){
                count++;
                res.push_back(matrix[i][right]);
            }
            if(count==m*n){
                break;
            }

            right--;

            // path 3
            for(int i=right; i>=left; i--){
                count++;
                res.push_back(matrix[bottom][i]);
            }
            if(count==m*n){
                break;
            }

            bottom--;
        
            // path 3
            for(int i=bottom; i>=top; i--){
                count++;
                res.push_back(matrix[i][left]);
            }
            if(count==m*n){
                break;
            }

            left++;
        }

        return res;
    }
};