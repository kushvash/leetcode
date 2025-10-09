class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u'
        };

        int count=0;
        for(char c: s) {
            if(vowels.find(c)!=vowels.end()) {
                count++;
            }
        }
        if(count==0) {
            return false;
        }

        return true;
    }
};