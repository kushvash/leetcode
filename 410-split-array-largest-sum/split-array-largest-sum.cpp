class Solution {
public:
    bool divPossible(int cap, vector<int>& nums, int k) {
        int currSum=0, currDiv=1;

        for(int num: nums) {
            if(currSum+num>cap) {
                currDiv++;
                currSum=num;
            }else {
                currSum+=num;
            }

            if(currDiv>k) {
                return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int lo=0, hi=0;

        for(int num: nums) {
            lo=max(lo, num);
            hi+=num;
        }

        while(lo<hi) {
            int mid=lo+(hi-lo)/2;

            if(divPossible(mid, nums, k)) {
                hi=mid;
            }else {
                lo=mid+1;
            }
        }

        return lo;
    }
};