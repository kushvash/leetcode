class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), sum=0, res=0;
        unordered_map<int, int> sumRecord;
        sumRecord[0]=-1;
        
        for(int i=0; i<n; i++) {
            if(nums[i]==1) {
                sum++;
            }else {
                sum--;
            }

            if(sumRecord.find(sum)!=sumRecord.end()) {
                res=max(res, i-sumRecord[sum]);
            }else {
                sumRecord[sum]=i;
            }
        }

        return res;
    }
};