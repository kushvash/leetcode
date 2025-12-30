class Solution {
public:
    string decodeString(string s) {
        vector<pair<string, int>> st;
        string curr;
        int num = 0;

        for (char c : s) {
            if (isdigit((unsigned char)c)) {
                num*=10;
                num+=(c - '0');
            } else if (c == '[') {
                st.push_back({curr, num});
                curr.clear();
                num = 0;
            } else if (c == ']') {
                auto [prev, k]=st.back();
                st.pop_back();

                string expanded;

                for (int i = 0; i < k; i++) {
                    expanded+=curr;
                }

                curr=prev+expanded;
            } else { 
                curr.push_back(c);
            }
        }
        return curr;
    }
};