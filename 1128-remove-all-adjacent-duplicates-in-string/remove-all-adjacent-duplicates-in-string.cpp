class Solution {
public:
    string removeDuplicates(string s) {
        string res;

        for(char c: s) {
            if(res.empty()) {
                res+=c;
            }else {
                int n=res.size()-1;

                if(c==res[n]) {
                    res.pop_back();
                }else {
                    res+=c;
                }
            }
        }

        return res;
    }
};