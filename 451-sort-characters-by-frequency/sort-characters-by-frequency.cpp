class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(char c: s) {
            mp[c]++;
        }

        vector<vector<char>> bucket(s.size()+1);

        string res;

        for(auto& [c, f]: mp) {
            bucket[f].push_back(c);
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