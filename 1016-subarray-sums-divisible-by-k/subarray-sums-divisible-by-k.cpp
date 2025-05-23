class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> record;
        record[0] = 1;         

        int currSum = 0, count = 0;
        for (int x : nums) {
            currSum += x;
            int mod = ((currSum % k) + k) % k;
            count += record[mod];
            record[mod]++;
        }
        return count;
    }
};