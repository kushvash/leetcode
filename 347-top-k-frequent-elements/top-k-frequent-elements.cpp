class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i: nums) {
            mp[i]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto& [i, c] : mp) {
            pq.push({c, i});
        }

        vector<int> res;

        for(int i=0; i<k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};