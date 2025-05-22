class Solution {
public:
    void letterCombinationsHelper(string& digits, int start, string& currSet, vector<string>& res) {
        if(start==digits.size()){
            if(currSet.size()>0){
                res.push_back(currSet);
            }
            return;
        }

        for(int i=0; i<dict[digits[start]].size(); i++) {
            currSet.push_back(dict[digits[start]][i]);
            letterCombinationsHelper(digits, start+1, currSet, res);
            currSet.pop_back();        
        }

        return;
    }
    
    unordered_map<char, string> dict = {
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"}
    };
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        string currSet="";

        letterCombinationsHelper(digits, 0, currSet, res);

        return res;
    }
};