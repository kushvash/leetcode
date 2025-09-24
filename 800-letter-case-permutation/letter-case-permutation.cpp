class Solution {
public:
    void dfs(string& s, int i, vector<string>& res) {
        // advance to next letter
        while (i < s.size() && !isalpha(s[i])) {
            i++;
        }

        if (i == s.size()) {
            res.push_back(s);
            return;
        }

        // branch: lowercase
        char orig = s[i];
        s[i] = tolower(orig);
        dfs(s, i + 1, res);

        // branch: uppercase
        s[i] = toupper(orig);
        dfs(s, i + 1, res);
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;

        dfs(s, 0, res);
        return res;
    }
};