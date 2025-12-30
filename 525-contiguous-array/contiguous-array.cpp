class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), currSum=0, res=0;

        unordered_map<int, int> lastOccur;
        lastOccur[0]=-1;

        for(int i=0; i<n; i++) {
            if(nums[i]==0) {
                currSum--;
            }else {
                currSum++;
            }

            if(lastOccur.find(currSum)!=lastOccur.end()) {
                res=max(res, i-lastOccur[currSum]);
            }else {
                lastOccur[currSum]=i;
            }
        }

        return res;
    }
};