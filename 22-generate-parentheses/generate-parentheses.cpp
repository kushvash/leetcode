class Solution {
public:
    void generateParenthesisHelper(int n, int openN, int closeN, vector<string>& res, string& curr) {
        if(openN==n && openN==closeN) {
            res.push_back(curr);
            return;
        }

        if(closeN<openN) {
            curr.push_back(')');
            generateParenthesisHelper(n, openN, closeN+1, res, curr);
            curr.pop_back();
        }
        if(openN<n) {
            curr.push_back('(');
            generateParenthesisHelper(n, openN+1, closeN, res, curr);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;

        generateParenthesisHelper(n, 0, 0, res, curr);
        
        return res;
    }
};