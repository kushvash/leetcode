class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size(), left=0;

        vector<string> st;

        while(left<n) {
            while(left<n && path[left]=='/') {
                left++;
            }

            if(left==n) {
                break;
            }

            int right=left;

            while(right<n && path[right]!='/') {
                right++;
            }

            string token=path.substr(left, right-left);

            if(token=="..") {
                if(!st.empty()) {
                    st.pop_back();
                }
            }else if(token!="." && !token.empty()) {
                st.push_back(token);
            }

            left=right;
        }

        if(st.empty()) {
            return "/";
        }

        string res;

        for(const string& dir: st) {
            res+='/';
            res+=dir;
        }

        return res;
    }
};