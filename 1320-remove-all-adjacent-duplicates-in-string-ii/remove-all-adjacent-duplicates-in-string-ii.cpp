class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for(char c: s) {
            if(st.empty()) {
                st.push({c, 1});
            }else {
                if(st.top().first==c) {
                    int topC=st.top().second;
                    st.pop();
                    if(topC+1<k) {
                        st.push({c, topC+1});
                    }
                }else {
                    st.push({c, 1});
                }
            }
        }

        string res;

        while(!st.empty()) {
            int n=st.top().second;
            char c=st.top().first;
            st.pop();

            for(int i=0; i<n; i++) {
                res+=c;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};