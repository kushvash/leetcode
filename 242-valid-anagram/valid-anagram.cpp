class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> helper;

        for(auto ch: s) {
            helper[ch]++;
        }

        for(auto ch: t) {
            if(helper[ch]==0 || helper.find(ch)==helper.end()) {
                return false;
            }
            helper[ch]--;

            if(helper[ch]==0) {
                helper.erase(ch);
            }
        }

        return helper.empty();
    }
};