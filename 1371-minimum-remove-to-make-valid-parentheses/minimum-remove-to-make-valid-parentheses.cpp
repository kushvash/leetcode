class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;

        int cnt=0;

        for(char c: s) {
            if(c=='(') {
                st.push(c);
                cnt++;
            }else if(c==')' && cnt>0) {
                st.push(c);
                cnt--;
            }else if(c!=')') {
                st.push(c);
            }
        }

        string res;

        while(!st.empty()) {
            char c=st.top();
            st.pop();

            if(c=='(' && cnt>0) {
                cnt--;
            }else {
                res+=c;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};