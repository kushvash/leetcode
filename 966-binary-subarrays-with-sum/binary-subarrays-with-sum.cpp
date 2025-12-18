class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0, res=0;
        unordered_map<int, int> sumFreq;

        sumFreq[0]=1;

        for(int num: nums) {
            sum+=num;
            
            if(sumFreq.find(sum-goal)!=sumFreq.end()) {
                res+=sumFreq[sum-goal];
            }
            
            sumFreq[sum]++;
        }

        return res;
    }
};