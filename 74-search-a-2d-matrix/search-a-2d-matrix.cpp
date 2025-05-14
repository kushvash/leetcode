class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo=0, hi=matrix.size()-1, mid, n=matrix[0].size()-1;

        while(lo<=hi){
            mid=lo+((hi-lo)/2);

            if(matrix[mid][n]==target){
                return true;
            }else if(matrix[mid][n]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }


        n=lo;

        if(lo>=matrix.size()){
            return false;
        }

        lo=0;
        hi=matrix[n].size()-1;

        while(lo<=hi){
            mid=lo+((hi-lo)/2);

            if(matrix[n][mid]==target){
                return true;
            }else if(matrix[n][mid]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return false;
    }
};