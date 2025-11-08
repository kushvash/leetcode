class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(), maxLength=0, l=0, r=0;
        unordered_set<char> record;

        while(r<n) {
            while(record.find(s[r])!=record.end()) {
                record.erase(s[l]);
                l++;
            }

            record.insert(s[r]);
            r++;

            maxLength=max(maxLength, r-l);
        }

        return maxLength;
    }
};