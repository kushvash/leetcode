class Solution {
public:
    bool ifPossible(vector<int>& weights, int days, int cap) {
        int currDay=1, currW=0;

        for(int w: weights) {
            if (currW + w > cap) {
                currDay++;
                currW = w;
            } else {
                currW += w;
            }

            if (currDay > days) {
                return false;
            }
        }

        return currDay<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo=1, mid, hi=0;

        for(int w: weights) {
            lo=max(lo, w);
            hi+=w;
        }

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(ifPossible(weights, days, mid)) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        return lo;
    }
};