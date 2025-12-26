class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size(), res=0;

        if(n<3) {
            return 0;
        }

        for(int i=1; i<n-1; i++) {
            char a=s[i-1], b=s[i], c=s[i+1];

            if(a!=b && b!=c && c!=a) {
                res++;
            }
        }

        return res;
    }
};