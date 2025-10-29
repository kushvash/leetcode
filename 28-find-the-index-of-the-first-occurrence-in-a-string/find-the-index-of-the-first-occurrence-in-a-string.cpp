class Solution {
public:
    bool helper(string haystack, string needle, int i) {
        for(int j=0; j<needle.size(); j++) {
            if(haystack[i]!=needle[j]) {
                return false;
            }
            i++;
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        for(int i=0; i<haystack.size(); i++) {
            if(haystack[i]==needle[0]) {
                if(helper(haystack, needle, i)) {
                    return i;
                }
            }
        }

        return -1;
    }
};