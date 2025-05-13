class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0, l=0, r=0;
        unordered_set<char> helper;


        while(r<s.size()){
            while(helper.find(s[r])!=helper.end()){
                helper.erase(s[l]);
                l++;
            }

            helper.insert(s[r]);
            
            longest=max(longest, r-l+1);
            
            if(r==s.size()-1){
                break;
            }
            r++;
        }

        return longest;
    }
};