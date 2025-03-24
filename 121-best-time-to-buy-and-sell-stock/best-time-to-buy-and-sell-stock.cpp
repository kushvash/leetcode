class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0], profit=0;

        for(int it: prices) {
            if(it<buy) {
                buy=it;
            }
            profit=max(profit, it-buy);    
        }

        return profit;
    }
};