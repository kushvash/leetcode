class Solution {
public:
    bool checkIfPangram(string sentence) {
        for(char c='a'; c<='z'; c++){
            bool helper=false;
            for(char cN:sentence){
                if(cN==c){
                    helper=true;
                    break;
                }
            }

            if(!helper){
                return false;
            }
        }

        return true;
    }
};