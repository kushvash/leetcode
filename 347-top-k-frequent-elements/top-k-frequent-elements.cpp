class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res;

        for(int& num: nums) {
            freq[num]++;
        }

        map<int, vector<int>, greater<int>> mp;

        for(auto& [key, value]: freq) {
            mp[value].push_back(key);
        }

        for(auto& [key, value]: mp) {
            for(int& num: value) {
                res.push_back(num);
                if(res.size()==k) {
                    break;
                }
            }
            if(res.size()==k) {
                break;
            }
        }

        return res;
    }
};