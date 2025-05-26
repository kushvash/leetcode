class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy=prices[0], maxP=0;

        for(int i=0; i<prices.size(); i++){
            bestBuy=min(bestBuy, prices[i]);
            maxP=max(maxP, prices[i]-bestBuy);
        } 

        return maxP;
    }
};