class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> record;
        int start=0, end=0, n=s.size(), ans=0;

        while(end<n) {
            while(record.find(s[end])!=record.end()){
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