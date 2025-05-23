class Solution {
public:
    bool checkPartition(vector<int>& nums, int k, int n) {
        int curr=0, partitions=0;

        for(int num:nums) {
            if(curr+num>n){
                partitions++;
                curr=0;
            }

            curr+=num;
        }

        if(curr!=0){
            partitions++;
        }

        return (partitions<=k);
    }

    int splitArray(vector<int>& nums, int k) {
        int lo=0, hi=0, mid;

        for(int num: nums) {
            hi+=num;
            lo=max(lo, num);
        }        

        while(lo<hi) {
            mid=lo+(hi-lo)/2;

            if(checkPartition(nums, k, mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }


        return lo;


    }
};