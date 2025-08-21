class Solution {
public:
    int compress(vector<char>& chars) {
        int currCnt=1, n=chars.size(), slow=0;

        for(int i=1; i<n; i++){
            if(chars[i]==chars[i-1]){
                currCnt++;
            }else{
                slow=addChar(chars, chars[i-1], slow, currCnt);
                currCnt=1;
            }
        }
        slow = addChar(chars, chars[n - 1], slow, currCnt);

        return slow;
    }

    int addChar(vector<char>& chars, char c, int pos, int cnt) {
        chars[pos] = c;                // write the character
        pos++;

        if (cnt > 1) {                   // only write digits if count > 1
            string s = to_string(cnt);
            for (char d : s) {
                chars[pos] = d;
                pos++;
            }
        }
        return pos;
    }
};