class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string& s: strs) {
            vector<int> tempKey(26, 0);

            for(char c: s) {
                tempKey[c-'a']++;
            }

            string key;

            for(int i: tempKey) {
                key+='#';
                key+=i;
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& [s, a]: mp) {
            res.push_back(a);
        }

        return res;
    }
};