class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0, right=matrix[0].size()-1, top=0, bottom=matrix.size()-1, count=0, m=matrix.size(), n=matrix[0].size();
        vector<int> res;

        while(top<=bottom && left<=right) {
            // top row (all elements)
            for(int i=left; i<=right; i++) {
                res.push_back(matrix[top][i]);
            }
            
            top++;

            // right column (all but first element)
            for(int i=top; i<=bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            
            right--;

            if(top>bottom) {
                break;
            }

            // bottom row (all but last element)
            for(int i=right; i>=left; i--) {
                res.push_back(matrix[bottom][i]);
            }
         
            bottom--;

            if(left>right) {
                break;
            }

            // left column (all but last element)
            for(int i=bottom; i>=top; i--) {
                res.push_back(matrix[i][left]);
            }

            left++;
        }

        return res;
    }
};