class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string& s: strs) {
            string temp=s;
            sort(temp.begin(), temp.end());

            mp[temp].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& [s, a]: mp) {
            res.push_back(a);
        }

        return res;
    }
};