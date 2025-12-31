class Solution {
public:
    string removeDuplicates(string s) {
        int write=0, n=s.size();

        for(int read=0; read<n; read++) {
            s[write]=s[read];

            if(write>0 && s[write]==s[write-1]) {
                write--;
            }else {
                write++;
            }
        }

        s.resize(write);

        return s;
    }
};