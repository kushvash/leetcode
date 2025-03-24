class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0], profit=0;

        for(int it: prices) {
            profit=max(profit, it-buy);
            if(it<buy) {
                buy=it;
            }
        }

        return profit;
    }
};