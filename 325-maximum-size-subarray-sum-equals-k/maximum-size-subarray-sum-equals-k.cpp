class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long sum=0; 
        int res=0;

        unordered_map<long long, int> sumIndices;
        sumIndices[0]=-1;
        
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];

            if(sumIndices.find(sum-k)!=sumIndices.end()) {
                res=max(res, i-sumIndices[sum-k]);
            }

            if(sumIndices.find(sum)==sumIndices.end()) {
                sumIndices[sum]=i;
            }
        }

        return res;
    }
};