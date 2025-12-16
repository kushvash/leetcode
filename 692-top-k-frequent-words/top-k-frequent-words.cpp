class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for(string& word: words) {
            mp[word]++;
        }

        auto cmp=[](pair<int, string>& a, pair<int, string>& b) {
            if(a.first==b.first) {
                return a.second<b.second;
            }

            return a.first>b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> minHeap(cmp);

        for(auto& [word, freq]: mp) {
            minHeap.push({freq, word});

            if(minHeap.size()>k) {
                minHeap.pop();
            }
        }

        vector<string> res;

        while(!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};