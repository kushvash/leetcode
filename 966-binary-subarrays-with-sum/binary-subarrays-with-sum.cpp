class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res=0, l=0, r=0, sum=0;

        unordered_map<int, int> mp;
        mp[0]=1;

        for(int num: nums) {
            sum+=num;

            if(mp.find(sum-goal)!=mp.end()) {
                res+=mp[sum-goal];
            }

            mp[sum]++;
        }

        return res;
    }
};