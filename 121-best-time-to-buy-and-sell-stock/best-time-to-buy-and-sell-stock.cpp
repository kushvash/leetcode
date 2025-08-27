class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0, bestBuy=prices[0];

        for(int i=0; i<prices.size(); i++){
            maxP=max(maxP, prices[i]-bestBuy);
            bestBuy=min(bestBuy, prices[i]);
        }

        return maxP;
    }
};