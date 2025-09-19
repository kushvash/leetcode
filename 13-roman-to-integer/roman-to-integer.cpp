class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> record = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n=s.size(), res=0;

        for(int i=0; i<n; i++) {
            char currentSymbol = s[i];
            int currentValue = record[currentSymbol];
            int nextValue = 0;
            // If a next value exists
            if (i + 1 < s.length()) {
                char nextSymbol = s[i + 1];
                nextValue = record[nextSymbol];
            }

            // If this is the subtractive case.
            if (currentValue < nextValue) {
                res += (nextValue - currentValue);
                i++;
            }else {
                res += currentValue;
            }
        }

        return res;
    }
};