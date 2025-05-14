class Solution {
public:
    double bananasFinished(vector<int>& piles, int speed){
        double total=0;
        for(int pile: piles){
            total+=pile / speed;

            if(pile%speed!=0){
                total++;
            }
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, mid, hi=0;

        for(int num: piles){
            hi=max(hi, num);
        }

        while(lo<=hi){
            mid=lo+((hi-lo)/2);

            if(bananasFinished(piles, mid)<=h){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return lo;
    }
};