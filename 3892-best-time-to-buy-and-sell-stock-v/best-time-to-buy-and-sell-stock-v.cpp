class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = -(1LL << 60);
        int n = (int)prices.size();
        if (n == 0 || k == 0) return 0;

        // dp0[t] = max profit after day i, flat (no position), with t completed transactions
        // dpL[t] = max profit after day i, holding a long, with t completed transactions
        // dpS[t] = max profit after day i, holding a short, with t completed transactions
        vector<long long> dp0(k + 1, NEG), dpL(k + 1, NEG), dpS(k + 1, NEG);

        dp0[0] = 0;
        dpL[0] = -prices[0]; // buy day 0
        dpS[0] =  prices[0]; // short-sell day 0

        for (int i = 1; i < n; ++i) {
            long long p = prices[i];
            vector<long long> ndp0(k + 1, NEG), ndpL(k + 1, NEG), ndpS(k + 1, NEG);

            for (int t = 0; t <= k; ++t) {
                // do nothing (carry states)
                ndp0[t] = max(ndp0[t], dp0[t]);
                ndpL[t] = max(ndpL[t], dpL[t]);
                ndpS[t] = max(ndpS[t], dpS[t]);

                // open a position today (from flat)
                if (dp0[t] > NEG/2) {
                    ndpL[t] = max(ndpL[t], dp0[t] - p); // buy
                    ndpS[t] = max(ndpS[t], dp0[t] + p); // short sell
                }

                // close a position today -> completes one transaction
                if (t + 1 <= k) {
                    if (dpL[t] > NEG/2) ndp0[t + 1] = max(ndp0[t + 1], dpL[t] + p); // sell
                    if (dpS[t] > NEG/2) ndp0[t + 1] = max(ndp0[t + 1], dpS[t] - p); // buy back
                }
            }

            dp0.swap(ndp0);
            dpL.swap(ndpL);
            dpS.swap(ndpS);
        }

        long long ans = 0;
        for (int t = 0; t <= k; ++t) ans = max(ans, dp0[t]); // best ends flat
        return ans;
    }
};