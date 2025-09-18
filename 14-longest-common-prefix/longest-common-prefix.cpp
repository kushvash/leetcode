class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string currMaxS=strs[0];

        for(int i=1; i<n; i++) {
            for(int j=0; j<currMaxS.size(); j++) {
                if(currMaxS[j]!=strs[i][j]) {
                    currMaxS=currMaxS.substr(0, j);
                }
            }
        }

        return currMaxS;
    }
};