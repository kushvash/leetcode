class Solution {
public:
    bool checkPalindrome(string s, int start, int end){
        int l=start, r=end;

        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void partitionHelper(string s, int start, vector<string> currSet, vector<vector<string>>& res){
        if(start==s.size()){
            res.push_back(currSet);
            return;
        }

        for(int i=start; i<s.size(); i++){
            if(checkPalindrome(s, start, i)){
                currSet.push_back(s.substr(start, i-start+1));
                partitionHelper(s, i+1, currSet, res);
                currSet.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        
        partitionHelper(s, 0, {}, res);

        return res;   
    }
};