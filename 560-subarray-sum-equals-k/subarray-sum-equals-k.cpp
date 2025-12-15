class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), res=0, sum=0;

        unordered_map<int, int> mp;

        mp[0]=1;

        for(int i=0; i<n; i++) {
            sum+=nums[i];

            int diff=sum-k;

            if(mp.find(diff)!=mp.end()) {
                res+=mp[diff];
            }

            mp[sum]++;
        }

        return res;
    }
};