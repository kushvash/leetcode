class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        string res;

        for(char c: s) {
            freqMap[c]++;
        }

        vector<vector<char>> bucket(s.size()+1);

        for(auto& [c, i]: freqMap) {
            bucket[i].push_back(c);
        }

        for(int i=s.size(); i>0; i--) {
            if(bucket[i].empty()) {
                continue;
            }

            for(char c: bucket[i]) {
                for(int j=0; j<i; j++) {
                    res+=c;
                }
            }
        }

        return res;
    }
};