class Solution {
public:
    vector<string> keyBoard={
        {""}, {""}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}
    };

    void helper(string digits, int i, string& curr, vector<string>& res) {
        if(i==digits.size()) {
            if(curr.size()>0) {
                res.push_back(curr);
            }
            return;
        }

        int dig=digits[i]-'0';
        
        for(int j=0; j<keyBoard[dig].size(); j++) {    
            char c=keyBoard[dig][j];
            curr.push_back(c);
            helper(digits, i+1, curr, res);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string curr;
        vector<string> res;

        helper(digits, 0, curr, res);
    
        return res;
    }
};