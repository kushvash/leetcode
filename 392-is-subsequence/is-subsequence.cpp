class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sN=s.size(), tN=t.size(), matches=0, sPoint=0;
        if(s==t) {
            return true;
        }

        if(t.empty()) {
            return false;
        }

        for(char c: t) {
            if(s[sPoint]==c) {
                sPoint++;
            }

            if(sPoint==sN) {
                return true;
            }
        }

        return false;


    }
};