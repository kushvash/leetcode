class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), res=0, sum=0;
        unordered_map<int, int> firstOccur;
        firstOccur[0]=-1;

        for(int i=0; i<n; i++) {
            if(nums[i]==0) {
                sum--;
            }else {
                sum++;
            }

            if(firstOccur.find(sum)!=firstOccur.end()) {
                res=max(res, i-firstOccur[sum]);
            }else {
                firstOccur[sum]=i;
            }     
        }

        return res;
    }
};