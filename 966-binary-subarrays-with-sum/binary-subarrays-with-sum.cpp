class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(), currSum=0, res=0;

        unordered_map<int, int> sumFreq;
        sumFreq[0]=1;

        for(int i=0; i<n; i++) {
            currSum+=nums[i];

            if(sumFreq.find(currSum-goal)!=sumFreq.end()) {
                res+=sumFreq[currSum-goal];
            }

            sumFreq[currSum]++;
        }

        return res;
    }
};