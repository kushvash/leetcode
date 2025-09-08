class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo=0, mid, hi=matrix.size()-1, n=matrix[0].size();

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(matrix[mid][n-1]>=target) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        n=lo;

        lo=0;
        hi=matrix[0].size()-1;

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(matrix[n][mid]>=target) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        return matrix[n][lo]==target;
    }
};