class Solution {
public:
    bool minEatingSpeedHelper(vector<int>& piles, int h, int speed) {
        int hours=0;

        for(int& b: piles) {
            hours+=b/speed;

            if(b%speed!=0) {
                hours++;
            }
        }

        return hours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, hi=0, mid;
        
        for(int num: piles) {
            hi=max(hi, num);
        }

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(minEatingSpeedHelper(piles, h, mid)) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        return lo;
    }
};