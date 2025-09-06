class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        vector<int> ans;
        
        int maxC=0;
        for(int& num: nums) {
            record[num]++;
            maxC=max(maxC, record[num]);
        }

        vector<vector<int>> finalHelper(maxC+1, vector<int>());

        for(auto& [num, count]: record) {
            finalHelper[count].push_back(num);
        }

        for(int i=maxC; i>0; i--) {
            for(int& num: finalHelper[i]) {
                ans.push_back(num);
            }
            if(ans.size()==k) {
                return ans;
            }
        }

        return ans;
    }
};