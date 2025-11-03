class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        auto cmp=[](pair<int, string>& a, pair<int, string>& b) {
            if(a.first==b.first) {
                return a.second>b.second;
            }
            return a.first<b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        vector<string> res;

        for(string& word: words) {
            freq[word]++;
        }


        for(auto& [word, f]: freq) {
            pq.push({f, word});
        }
        
        for(int i=0; i<k; i++) {
            auto [f, word]=pq.top();
            pq.pop();

            res.push_back(word);
        }

        return res;
    }
};