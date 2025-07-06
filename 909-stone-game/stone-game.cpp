class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int start=0, end=piles.size()-1, alice=0, bob=0;

        while(start<=end){
            if(piles[start]>piles[end]){
                alice+=piles[start];
                start++;
            }else{
                alice+=piles[end];
                end--;
            }


            if(start<end){
                break;
            }

            if(piles[start]>piles[end]){
                bob+=piles[start];
                start++;
            }else{
                bob+=piles[end];
                end--;
            }
        }


        return alice>bob;
    }
};