class Solution {
public:
    bool validPalindromeHelper(string s, int l, int r) {
        while(l<r) {
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
            
        }

        return true;
    }

    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;

        while(l<r) {
            if(s[l]!=s[r]){
                return (validPalindromeHelper(s, l, r-1) || validPalindromeHelper(s, l+1, r));
            }else{
                l++;
                r--;
            }
        }

        return true;
    }
};