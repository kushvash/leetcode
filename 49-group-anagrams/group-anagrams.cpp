class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;
        string temp;
        for(string i: strs) {
            temp=i;

            sort(temp.begin(), temp.end());
            record[temp].push_back(i);
        }

        vector<vector<string>> ans;

        for(auto i: record){
            ans.push_back(i.second);
        }

        return ans;

    }
};