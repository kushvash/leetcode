class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int currMax=0;
        unordered_map<int, int> counts;

        for(int& num: nums){
            counts[num]++;
            currMax=max(currMax, counts[num]);
        }

        vector<vector<int>> record(currMax+1);

        for(auto& [val, freq]: counts){
            record[freq].push_back(val);
        }

        vector<int> ans;

        for(int i=currMax; i>=0 && ans.size()<k; i--){
            for(auto j: record[i]){
                ans.push_back(j);
            }
        }

        return ans;
    }
};