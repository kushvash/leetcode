class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> record;
        int l=0, r=0, maxL=0;

        while(r<s.size()){
            while(record.find(s[r]) != record.end()){
                record.erase(s[l]);
                l++;
            }

            record.insert(s[r]);
            maxL=max(maxL, r-l+1);

            r++;


        }

        return maxL;

    }
};