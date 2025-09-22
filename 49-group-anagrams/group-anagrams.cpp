class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        
        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(count[i]);
            }
            ans[key].push_back(s);
        }
        
        vector<vector<string>> result;
        
        for (auto& itr: ans) {
            result.push_back(itr.second);
        }

        return result;
    }
};