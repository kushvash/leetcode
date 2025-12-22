class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, res=0, n=s.size();

        unordered_set<char> charRecord;

        for(int r=0; r<n; r++) {
            while(charRecord.find(s[r])!=charRecord.end()) {
                charRecord.erase(s[l]);
                l++;
            }

            charRecord.insert(s[r]);

            res=max(res, r-l+1);
        }

        return res;
    }
};