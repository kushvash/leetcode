class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), maxL=0;
        vector<int> dp(n, 0);

        if(n==0){
            return 0;
        }
        
        for(int i=1; i<n; i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=2;
                    if(i>=2){
                        dp[i]+=dp[i-2];
                    }
                }
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                    dp[i]=dp[i-1]+2;
                    if(i-dp[i-1]-2>=0){
                        dp[i]+=dp[i-dp[i-1]-2];
                    }
                }
            }

            maxL=max(maxL, dp[i]);
        }

        return maxL;
    }
};