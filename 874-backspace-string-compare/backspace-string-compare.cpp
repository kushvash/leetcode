class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sSt;
        stack<char> tSt;

        for(char c: s) {
            if(c=='#') {
                if(!sSt.empty()) {
                    sSt.pop();
                }
            }else {
                sSt.push(c);
            }
        }

        for(char c: t) {
            if(c=='#') {
                if(!tSt.empty()) {
                    tSt.pop();
                }
            }else {
                tSt.push(c);
            }
        }

        while(!sSt.empty() && !tSt.empty()) {
            if(sSt.top()!=tSt.top()) {
                return false;
            }

            sSt.pop();
            tSt.pop();
        }

        return sSt.empty() && tSt.empty();
    }
};