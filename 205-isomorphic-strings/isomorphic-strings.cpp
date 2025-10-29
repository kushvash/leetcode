class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i=0; i<n; i++) {
            char c1=s[i], c2=t[i];

            if(mp1.find(c1)==mp1.end() && mp2.find(c2)==mp2.end()) {
                mp1[c1]=c2;
                mp2[c2]=c1;
            }else if(mp1[c1]!=c2 && mp2[c2]!=c1) {
                return false;
            }
        }

        return true;
    }
};