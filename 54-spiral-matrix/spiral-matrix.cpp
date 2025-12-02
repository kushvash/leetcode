class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> res;

        while (top <= bottom && left <= right) {
            // Traverse right along top row
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // Traverse down along right column
            for (int j = top; j <= bottom; j++) {
                res.push_back(matrix[j][right]);
            }
            right--;

            // Traverse left along bottom row (if exists)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse up along left column (if exists)
            if (left <= right) {
                for (int j = bottom; j >= top; j--) {
                    res.push_back(matrix[j][left]);
                }
                left++;
            }
        }

        return res;
    }
};