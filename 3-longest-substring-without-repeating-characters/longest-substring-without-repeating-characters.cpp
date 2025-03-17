class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left=0, right=0, n=s.length(), l=0, maxL=0;
        set<char> set;


        while(right<n){
            if(set.find(s[right])!=set.end()){
                while(s[left]!=s[right]){
                    set.erase(s[left]);
                    left++;
                    l--;
                }
                set.erase(s[left]);
                left++;
                l--;
            }else{
                set.insert(s[right]);
                right++;
                l++;
                maxL=max(maxL, l);
            }
        }

        return maxL;

    }
};