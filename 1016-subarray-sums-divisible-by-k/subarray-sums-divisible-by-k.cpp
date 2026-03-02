class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]=1;

        int sum=0, res=0;

        for(int num: nums) {
            sum=(sum+num)%k;

            if(sum<0) {
                sum+=k;
            }

            if(mp.find(sum)!=mp.end()) {
                res+=mp[sum];
            }

            mp[sum]++;
        }

        return res;
    }
};