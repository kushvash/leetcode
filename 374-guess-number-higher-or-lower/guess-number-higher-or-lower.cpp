/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo=1, hi=n, mid;

        while(lo<hi){
            mid=lo+(hi-lo)/2;

            int res = guess(mid);
            if(res<=0) {
                hi=mid;
            }else{
                lo=mid+1;
            }
        }

        return lo;
    }
};