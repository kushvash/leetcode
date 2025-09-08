class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> record;

        record[']']='[';
        record['}']='{';
        record[')']='(';
        
        for(char& c: s) {
            if(record.find(c)==record.end()) {
                st.push(c);
            }else {
                if(st.empty() || st.top()!=record[c]) {
                    return false;
                }else{
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};