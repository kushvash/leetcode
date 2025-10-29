class Solution {
public:
    int mySqrt(int x) {
        if(x<2) {
            return x;
        }

        int lo=1, hi=x/2, mid;

        while(lo<hi) {
            mid=lo+(hi-lo+1)/2;

            if(mid>x/mid) {
                hi=mid-1;
            }else {
                lo=mid;
            }
        }

        return lo;
    }
};