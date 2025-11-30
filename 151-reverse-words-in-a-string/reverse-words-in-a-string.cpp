class Solution {
public:
    string reverseWords(string s) {
        int end=s.size()-1;
        string res;

        while(end>=0) {
            while(end>=0 && s[end]==' ') {
                end--;
            }

            if(end<0) {
                break;
            }

            int start=end;

            while(start>=0 && s[start]!=' ') {
                start--;
            }

            res+=s.substr(start+1, end-start);
            res+=' ';

            end=start-1;
        }

        if(!res.empty()) {
            res.pop_back();
        }

        return res;
    }
};