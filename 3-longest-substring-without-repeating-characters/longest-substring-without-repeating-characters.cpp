class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0, l=0, r=1;
        unordered_set<char> helper;

        if(s.size()==0 || s.size()==1){
            return s.size();
        }

        helper.insert(s[0]);

        while(l<s.size()-1){
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