class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> pos(26);

        int prev=-1;

        for(int i=0; i<t.size(); i++) {
            char c=t[i];

            pos[c-'a'].push_back(i);
        }

        for(int i=0; i<s.size(); i++) {
            char c=s[i];

            vector<int> positions=pos[c-'a'];

            auto it=upper_bound(positions.begin(), positions.end(), prev);

            if(it==positions.end()) {
                return false;
            }

            prev=*it;
        }

        return true;
    }
};