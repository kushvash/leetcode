class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy=INT_MAX, res=0, n=prices.size();

        for(int i=0; i<n; i++) {
            res=max(res, prices[i]-bestBuy);
            bestBuy=min(bestBuy, prices[i]);
        }

        return res;
    }
};