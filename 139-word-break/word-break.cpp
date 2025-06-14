class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> record;

        for(string s: wordDict){
            record.insert(s);
        }
        int n=s.size();
        vector<bool> dp(n+1, false);
        dp[n]=true;


        for(int i=n-1; i>=0; i--){
            string t="";

            for(int j=i; j<n; j++){
                t+=s[j];

                if(record.find(t)!=record.end() && dp[j+1]){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[0];
    }
};