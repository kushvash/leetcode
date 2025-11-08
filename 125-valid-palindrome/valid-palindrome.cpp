class Solution {
public:
    bool isAlphaNumeric(char c) {
        c=tolower(c);
        if((c>='a' && c<='z') || (c>='0' && c<='9')){
            return true;
        }

        return false;
    }
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;

        while(l<r) {
            while(l<r && !isAlphaNumeric(s[l])) {
                l++;
            }
            while(l<r && !isAlphaNumeric(s[r])) {
                r--;
            }

            if(l<r && tolower(s[l])!=tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};