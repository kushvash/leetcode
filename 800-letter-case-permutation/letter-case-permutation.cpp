class Solution {
public:
    void helper(string s, int i, string curr, vector<string>& res) {
        while(i<s.size() && !(isalpha(s[i]))) {
            curr.push_back(s[i]);
            i++;
        }

        if(i==s.size()) {
            res.push_back(curr);
            return;
        }

        // using lowercase
        curr.push_back(tolower(s[i]));
        helper(s, i+1, curr, res);
        
        curr.pop_back();

        // using uppercase
        curr.push_back(toupper(s[i]));
        helper(s, i+1, curr, res);
    }

    vector<string> letterCasePermutation(string s) {
        string curr="";
        vector<string> res;

        helper(s, 0, curr, res);

        return res;
    }
};