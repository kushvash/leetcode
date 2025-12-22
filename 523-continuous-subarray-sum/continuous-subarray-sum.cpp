class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(), modSum=0;
        // vector<int> prefixSumMod(n+1, 0);
        unordered_map<int, int> prefixSumMod;
        prefixSumMod[0]=-1;

        for(int i=0; i<n; i++) {
            modSum=(modSum+nums[i])%k;
            if(prefixSumMod.find(modSum)!=prefixSumMod.end()) {
                if(i-prefixSumMod[modSum]>1) {
                    return true;
                }
            }else {
                prefixSumMod[modSum]=i;
            }
        }

        return false;
    }
};