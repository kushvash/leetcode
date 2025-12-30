class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();

        unordered_map<string, int> freqMap;

        auto cmp=[](pair<int, string>& a, pair<int, string>& b) {
            if(a.first==b.first) {
                return a.second<b.second;
            }

            return a.first>b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> heap(cmp);

        vector<string> res;

        for(string& word: words) {
            freqMap[word]++;
        }

        for(auto& [word, freq]: freqMap) {
            heap.push({freq, word});

            if(heap.size()>k) {
                heap.pop();
            }
        }

        while(!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};