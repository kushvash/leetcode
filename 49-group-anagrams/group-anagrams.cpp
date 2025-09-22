class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;

        for(string& s: strs) {
            string i=s;
            sort(i.begin(), i.end());
            record[i].push_back(s);
        }

        vector<vector<string>> res;

        for(auto& i: record) {
            res.push_back(i.second);
        }

        return res;
    }
};