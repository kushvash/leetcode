class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        record[0]=1;

        int currSum=0, count=0;

        for(int i: nums){
            currSum+=i;

            count+=record[currSum-k];

            record[currSum]++;
        }

        return count;

    }
};