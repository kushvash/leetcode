class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(char c: s) {
            mp[c]++;
        }

        vector<pair<int, char>> records;

        for(auto& [c, freq]: mp) {
            records.push_back({freq, c});
        }

        auto cmp=[](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first>b.first;
        };

        sort(records.begin(), records.end(), cmp);

        string res;

        for(auto& record: records) {
            for(int i=0; i<record.first; i++) {
                res+=record.second;
            }
        }

        return res;
    }
};