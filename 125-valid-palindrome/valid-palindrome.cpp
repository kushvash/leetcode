class Solution {
public:
    bool isNotAlphaNum(char c) {
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) {
            return false;
        }

        return true;
    }

    bool isPalindrome(string s) {
        int left=0, right=s.size()-1;

        while(left<right) {
            while(left<right && isNotAlphaNum(s[left])) {
                left++;
            }
            while(left<right && isNotAlphaNum(s[right])) {
                right--;
            }

            if(left>=right) {
                break;
            }

            if(tolower(s[left])==tolower(s[right])) {
                left++;
                right--;
            }else {
                return false;
            }
        }

        return true;
    }
};