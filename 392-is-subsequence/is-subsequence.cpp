class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPoint=0, tPoint=0, sSize=s.size(), tSize=t.size();

        if(sSize>tSize) {
            return false;
        }

        while(sPoint<sSize && tPoint<tSize) {
            if(s[sPoint]==t[tPoint]) {
                sPoint++;
                tPoint++;
            }else {
                tPoint++;
            }
        }

        return sPoint==sSize;
    }
};