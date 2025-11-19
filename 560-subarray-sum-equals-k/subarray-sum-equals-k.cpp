class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), res=0, sum=0;
        unordered_map<int, int> sumRecord;
        sumRecord[0]=1;

        for(int i=0; i<n; i++) {
            sum+=nums[i];

            if(sumRecord.find(sum-k)!=sumRecord.end()) {
                res+=sumRecord[sum-k];
            }

            sumRecord[sum]++;
        }

        return res;
    }
};