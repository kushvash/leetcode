class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), ans=0;
        vector<int> dp(n, 0);

        if(n==0){
            return 0;
        }

        for(int i=1; i<n; i++){
            if(s[i]==')'){
                // Case 1: “( )”
                if (s[i-1] == '(') {
                    dp[i] = 2 + (i >= 2 ? dp[i-2] : 0);
                }
                // Case 2: “))” and the char before the previous valid is “(”
                else if (i - dp[i-1] - 1 >= 0 
                    && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + 2;
                    // add any valid before that match
                    if (i - dp[i-1] - 2 >= 0) {
                        dp[i] += dp[i - dp[i-1] - 2];
                    }
                }
            }
            ans=max(ans, dp[i]);
        }

        return ans;
    }
};