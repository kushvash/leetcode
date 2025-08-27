class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> record;
        int l=0, r=0, n=s.size(), ans=0;

        while(r<n){
            while(record.find(s[r])!=record.end()){
                record.erase(s[l]);
                l++;
            }
            record.insert(s[r]);
            r++;
            ans=max(ans, r-l);
        }

        return ans;
    }
};