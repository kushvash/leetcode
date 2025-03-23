class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> helper;
        string temp;
        vector<vector<string>> ans;

        for(auto s: strs) {
            temp=s;
            sort(temp.begin(), temp.end());

            helper[temp].push_back(s);
        }

        for(auto it: helper) {
            ans.push_back(it.second);
        }

        return ans;

    }
};