class Solution {
public:
    int nextValidIndex(int i, string str) {
        int skip=0;

        while(i>=0) {
            if(str[i]=='#') {
                skip++;
                i--;
            }else if(skip>0) {
                skip--;
                i--;
            }else {
                break;
            }   
        }

        return i;
    }
    bool backspaceCompare(string s, string t) {
        int sP=s.size()-1, tP=t.size()-1;

        while(sP>=0 || tP>=0) {
            sP=nextValidIndex(sP, s);
            tP=nextValidIndex(tP, t);

            if(sP<0 && tP<0) {
                return true;
            }

            if((sP<0 || tP<0)) {
                return false;
            }

            if(s[sP]!=t[tP]) {
                return false;
            }

            sP--;
            tP--;
        }

        return true;
    }
};