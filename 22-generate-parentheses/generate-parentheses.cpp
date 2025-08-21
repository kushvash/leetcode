class Solution {
public:
    void generateParenthesisHelper(int n, int open, int close, string curr, vector<string>& res){
        if(open==n && open==close){
            res.push_back(curr);
            return;
        }

        if(open<n){
            curr.push_back('(');
            generateParenthesisHelper(n, open+1, close, curr, res);
            curr.pop_back();
        }

        if(close<open){
            curr.push_back(')');
            generateParenthesisHelper(n, open, close+1, curr, res);
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        generateParenthesisHelper(n, 0, 0, "", ans);

        return ans;
    }
};