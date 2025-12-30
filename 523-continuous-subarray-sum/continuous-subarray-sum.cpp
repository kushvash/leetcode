class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(), modSum=0;

        unordered_map<int, int> modMap;

        modMap[0]=-1;

        for(int i=0; i<n; i++) {
            modSum+=nums[i];
            modSum%=k;

            if(modMap.find(modSum)!=modMap.end() && i-modMap[modSum]>1) {
                return true;
            }

            if(modMap.find(modSum)==modMap.end()) {
                modMap[modSum]=i;
            }
        }

        return false;
    }
};