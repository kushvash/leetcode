class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int res=strs[0].size(), n=strs.size();

        for(int i=1; i<n; i++) {
            for(int j=0; j<res; j++) {
                if(strs[0][j]!=strs[i][j]) {
                    res=j;
                    break;
                }
            }
        }

        return strs[0].substr(0, res);
    }
};