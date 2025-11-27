class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1, res=0;

        while(n>=0 && s[n]==' ') {
            n--;
        }

        while(n>=0 && s[n]!=' ') {
            n--;
            res++;
        }

        return res;
    }
};