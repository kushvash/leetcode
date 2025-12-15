class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(), prefModSum=0;
        unordered_map<int, int> mp;
        mp[0]=-1;

        for(int i=0; i<n; i++) {
            prefModSum+=nums[i];
            prefModSum%=k;

            if(mp.find(prefModSum)!=mp.end()) {
                if(i-mp[prefModSum]>1) {
                    return true;
                }
            }else {
                mp[prefModSum]=i;
            }
        }

        return false;
    }
};