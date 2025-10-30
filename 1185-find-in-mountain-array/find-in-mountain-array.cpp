/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr, int hi) {
        int lo=0, mid;

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(mountainArr.get(mid)>mountainArr.get(mid+1)) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        return lo;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int lo=0, mid, hi=mountainArr.length()-1;

        int peak=findPeak(mountainArr, hi);

        hi=peak;

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(mountainArr.get(mid)>=target) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        if(mountainArr.get(lo)==target) {
            return lo;
        }

        lo=peak;
        hi=mountainArr.length()-1;

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(mountainArr.get(mid)<=target) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        if(mountainArr.get(lo)==target) {
            return lo;
        }

        return -1;
    }
};