class Solution {
public:
    void generateParenthesisHelper(int n, int open, int close, string currStr, vector<string>& res) {
        if(open==n && open==close){
            res.push_back(currStr);
            return;
        }

        // open braket
        if(open<n) {
            currStr.push_back('(');
            // open++;
            generateParenthesisHelper(n, open+1, close, currStr, res);
            currStr.pop_back();
            // open--;
        }

        // close braket
        if(close<open) {
            currStr.push_back(')');
            // close++;
            generateParenthesisHelper(n, open, close+1, currStr, res);
            currStr.pop_back();
            // close--;
        }

        return;
    }


    vector<string> generateParenthesis(int n) {
        vector<string> res;

        generateParenthesisHelper(n, 0, 0, "", res);
    
        return res;
    }
};