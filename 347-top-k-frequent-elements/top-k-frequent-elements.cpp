class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        vector<int> res;

        for(int& num: nums) {
            freqs[num]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto& [num, freq]: freqs) {
            bucket[freq].push_back(num);
        }

        for(int i=nums.size(); i>=0 && res.size()<k; i--) {
            for(int& num: bucket[i]) {
                res.push_back(num);
                if(res.size()==k) {
                    break;
                }
            }
        }

        return res;
    }
};