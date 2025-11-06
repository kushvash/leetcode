class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i: nums) {
            mp[i]++;
        }

        auto cmp=[] (pair<int, int> a, pair<int, int> b) {
            if(a.first==b.first) {
                return a.second>b.second;
            }
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;


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