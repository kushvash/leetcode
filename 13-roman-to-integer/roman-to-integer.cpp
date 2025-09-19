class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> record = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n=s.size(), res=0;

        for(int i=0; i<n; i++) {
            if(s[i]=='I') {
                if(i<n-1 && s[i+1]=='V') {
                    res+=4;
                    i++;
                }else if(i<n-1 && s[i+1]=='X') {
                    res+=9;
                    i++;
                }else {
                    res+=record[s[i]];
                }
            }else if(s[i]=='X') {
                if(i<n-1 && s[i+1]=='L') {
                    res+=40;
                    i++;
                }else if(i<n-1 && s[i+1]=='C') {
                    res+=90;
                    i++;
                }else {
                    res+=record[s[i]];
                }
            }else if(s[i]=='C') {
                if(i<n-1 && s[i+1]=='D') {
                    res+=400;
                    i++;
                }else if(i<n-1 && s[i+1]=='M') {
                    res+=900;
                    i++;
                }else {
                    res+=record[s[i]];    
                }
            }else {
                res+=record[s[i]];
            }
        }

        return res;
    }
};