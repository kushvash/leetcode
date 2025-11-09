class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s: tokens) {
            if(s=="+" || s=="-" || s=="*" || s=="/") {
                int n1, n2;
                n1=st.top();
                st.pop();
                n2=st.top();
                st.pop();

                int next;

                if(s=="+") {
                    next=n1+n2;
                }else if(s=="-") {
                    next=n2-n1;
                }else if(s=="*") {
                    next=n1*n2;
                }else {
                    next=n2/n1;
                }

                st.push(next);
            }else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};