class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();

        vector<vector<string>> freqList(n);

        unordered_map<string, int> freqMap;

        vector<string> res;

        for(string& word: words) {
            freqMap[word]++;
        }

        for(auto& [word, freq]: freqMap) {
            freqList[freq].push_back(word);
        }

        for(int i=n-1; i>=0; i--) {
            if(freqList[i].empty()) {
                continue;
            }

            sort(freqList[i].begin(), freqList[i].end());

            for(string& word: freqList[i]) {
                res.push_back(word);

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