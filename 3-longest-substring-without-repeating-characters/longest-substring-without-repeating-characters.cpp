class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, res=0, n=s.size();

        unordered_map<char, int> charRecord;

        for(int r=0; r<n; r++) {
            // while(charRecord.find(s[r])!=charRecord.end()) {
            //     charRecord.erase(s[l]);
            //     l++;
            // }
            if(charRecord.find(s[r])!=charRecord.end()) {
                l=max(l, charRecord[s[r]]+1);
            }

            charRecord[s[r]]=r;

            res=max(res, r-l+1);
        }

        return res;
    }
};