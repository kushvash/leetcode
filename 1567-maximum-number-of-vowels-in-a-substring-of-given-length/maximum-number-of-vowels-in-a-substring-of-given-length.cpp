class Solution {
public:
    int maxVowels(string s, int k) {
        int res=0, n=s.size(), left=0, right=0, currCount=0;

        unordered_set<char> vowels={
            'a', 'e', 'i', 'o', 'u' 
        };

        if(n<k) {
            return 0;
        }

        while(right<k) {
            if(vowels.find(s[right])!=vowels.end()) {
                currCount++;
            }
            right++;
        }

        res=currCount;

        while(right<n) {
            char rChar=s[right];
            char lChar=s[left];

            if(vowels.find(rChar)!=vowels.end()) {
                currCount++;
            }
            if(vowels.find(lChar)!=vowels.end()) {
                currCount--;
            }

            res=max(res, currCount);
            left++;
            right++;
        }

        return res;
    }
};