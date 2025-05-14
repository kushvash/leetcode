class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo=0, hi=matrix.size()-1, mid;

        while(lo<=hi){
            mid=lo+((hi-lo)/2);

            if(matrix[mid][0]==target){
                return true;
            }else if(matrix[mid][0]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }


        int n=hi;

        if(hi<0){
            return false;
        }
        // if(matrix[n][0]>target){
        //     return false;
        // }

        // cout<<n;

        // return true;

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