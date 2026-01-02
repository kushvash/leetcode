class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n=nums.size(), sum=0, res=0;
        mp[0]=-1;

        for(int i=0; i<n; i++) {
            if(nums[i]==1) {
                sum++;
            }else {
                sum--;
            }

            if(mp.find(sum)!=mp.end()) {
                res=max(res, i-mp[sum]);
            }else {
                mp[sum]=i;
            }
        }

        return res;
    }
};