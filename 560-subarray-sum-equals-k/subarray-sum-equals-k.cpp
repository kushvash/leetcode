class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), res=0, sum=0;

        unordered_map<int, int> mp;
        
        mp[0]=1;

        for(int num: nums) {
            sum+=num;

            if(mp.find(sum-k)!=mp.end()) {
                res+=mp[sum-k];
            }

            mp[sum]++;
        }

        return res;
    }
};