class Solution {
public:
    void dfs(string& s, int i, vector<string>& res) {
        // advance to next letter
        while (i < (int)s.size() && !isalpha(s[i])) ++i;

        if (i == (int)s.size()) {            // one permutation ready
            res.push_back(s);
            return;
        }

        // branch: lowercase
        char orig = s[i];
        s[i] = tolower(static_cast<unsigned char>(orig));
        dfs(s, i + 1, res);

        // branch: uppercase
        s[i] = toupper(static_cast<unsigned char>(orig));
        dfs(s, i + 1, res);

        // restore (not strictly needed since we overwrite both branches, but good hygiene)
        s[i] = orig;
    }

    vector<string> letterCasePermutation(string s) {
        // reserve to avoid reallocations
        int k = 0;
        for (char c : s) {
            if (isalpha(c)) {   
                k++;
            }
        }
        vector<string> res;
        res.reserve(1 << k);

        dfs(s, 0, res);
        return res;
    }
};