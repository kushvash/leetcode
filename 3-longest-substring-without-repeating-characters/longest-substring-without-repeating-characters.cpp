class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> helper;

        int start=0, end=0, l=0;

        while(end<s.length()) {
            while(helper.find(s[end])!=helper.end()) {
                helper.erase(s[start]);
                start++;
            }

            helper.insert(s[end]);

            l=max(l, end-start+1);
            end++;
        }

        return l;


    }
};