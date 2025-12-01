class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0, n1=s.size(), n2=t.size();

        if(n2<n1) {
            return false;
        }

        if(n1==0) {
            return true;
        }


        for(int i=0; i<n2; i++) {
            if(s[j]==t[i]) {
                j++;
            }

            if(j==n1) {
                return true;
            }
        }

        return false;
    }
};