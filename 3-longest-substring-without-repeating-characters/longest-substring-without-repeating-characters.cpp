class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0, end=0, n=s.size(), ans=0;
        unordered_set<char> record;

        while(end<n) {
            while(start<end && record.find(s[end])!=record.end()) {
                record.erase(s[start]);
                start++;
            }

            record.insert(s[end]);
            ans=max(ans, end-start+1);
            end++;
        }

        return ans;
    }
};