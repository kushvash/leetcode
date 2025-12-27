class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();

        for(int i=0; i<n; i++) {
            string token=tokens[i];

            if(token=="+") {
                int i1=st.top();
                st.pop();
                int i2=st.top();
                st.pop();

                st.push(i2+i1);
            }else if(token=="-") {
                int i1=st.top();
                st.pop();
                int i2=st.top();
                st.pop();

                st.push(i2-i1);
            }else if(token=="*") {
                int i1=st.top();
                st.pop();
                int i2=st.top();
                st.pop();

                st.push(i2*i1);
            }else if(token=="/") {
                int i1=st.top();
                st.pop();
                int i2=st.top();
                st.pop();

                st.push(i2/i1);
            }else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};