class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> helper(26, false);

        for(char c: sentence){
            helper[c-'a']=true;
        }

        for(int i=0; i<helper.size(); i++){
            if(!helper[i]){
                return false;
            }
        }

        return true;
    }
};