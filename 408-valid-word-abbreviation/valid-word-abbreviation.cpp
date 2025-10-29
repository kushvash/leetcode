class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int word_i = 0, abbr_i = 0;
        while(word_i < word.length() && abbr_i < abbr.length()) {
            if (word[word_i] == abbr[abbr_i]) {
                word_i++;
                abbr_i++;
            } else if (abbr[abbr_i] > '0' && abbr[abbr_i] <= '9') {
                int num = 0;
                while (abbr[abbr_i] >= '0' && abbr[abbr_i] <= '9') {
                    num = num * 10 + (abbr[abbr_i] - '0');
                    abbr_i++;
                }
                word_i += num;
            } else {
                return false;
            }

        }
        return (word_i == word.length()) && (abbr_i == abbr.length());
    }
};