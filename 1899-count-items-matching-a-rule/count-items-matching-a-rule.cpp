class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n, count=0;
        if(ruleKey == "type"){
            n=0;
        }else if(ruleKey == "color"){
            n=1;
        }else{
            n=2;
        }

        for(vector<string> curr: items){
            if(curr[n]==ruleValue){
                count++;
            }
        }

        return count;

    }
};