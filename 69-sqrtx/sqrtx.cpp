class Solution {
public:
    int mySqrt(int target) {
        if (target < 2){
            return target;
        } 


        int lo=1, hi=target/2, mid;

        while(lo<hi){
            mid=lo+(hi-lo+1)/2;

            if(mid>target/mid){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }

        return lo;
    }
};