class Solution {
public:
    string helper(string s) {
        unordered_map<char, int> mp;
        int n=s.size();
        string res;

        for(int i=0; i<n; i++) {
            char c=s[i];
            if(mp.find(c)==mp.end()) {
                mp[c]=i;
            }

            res+=to_string(mp[c]);
            res+=" ";
        }

        return res;
    }

    bool isIsomorphic(string s, string t) {
        return helper(s)==helper(t);
    }
};