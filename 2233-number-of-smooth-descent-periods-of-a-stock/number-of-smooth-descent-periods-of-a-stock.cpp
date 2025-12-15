class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res=prices.size();
        int n=prices.size(), currP=1;

        for(int i=1; i<n; i++) {
            if(prices[i-1]-prices[i]==1) {
                res+=currP;
                currP++;
            }else {
                currP=1;
            }
        }

        return res;
    }
};