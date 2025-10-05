class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(char& c: s) {
            freq[c]++;
        }

        vector<vector<char>> bucket(s.size()+1);

        string res;

        for(auto& [c, f]: freq) {
            bucket[f].push_back(c);
        }

        for(int i=s.size(); i>0; i--) {
            if(bucket[i].empty()) {
                continue;
            }

            while(!bucket[i].empty()) {
                res.append(i, bucket[i].back());
                bucket[i].pop_back();
            }
        }

        return res;   
    }
};