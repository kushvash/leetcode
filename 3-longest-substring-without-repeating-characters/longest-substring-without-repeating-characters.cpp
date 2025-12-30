class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0, res=0, n=s.size();
        unordered_set<char> charFound;

        while(right<n) {
            while(charFound.find(s[right])!=charFound.end()) {
                charFound.erase(s[left]);
                left++;
            }

            charFound.insert(s[right]);

            res=max(res, right-left+1);

            right++;
        }

        return res;
    }
};