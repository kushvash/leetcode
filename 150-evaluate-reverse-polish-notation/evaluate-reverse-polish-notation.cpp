class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> record={
            "+", "-", "/", "*"
        };
        stack<int> st;

        for(string& token: tokens) {
            if(record.find(token)==record.end()) {
                st.push(stoi(token));
            }else {
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();

                if(token=="+") {
                    st.push(num1+num2);
                }else if(token=="-") {
                    st.push(num2-num1);
                }else if(token=="/") {
                    st.push(num2/num1);
                }else {
                    st.push(num1*num2);
                }
            }
        }

        return st.top();
    }
};