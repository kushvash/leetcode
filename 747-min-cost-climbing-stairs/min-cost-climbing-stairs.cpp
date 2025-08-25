class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> costs(n, 0);
        costs[0]=cost[0];
        costs[1]=cost[1];

        for(int i=2; i<n; i++){
            costs[i]=cost[i]+min(costs[i-1], costs[i-2]);
        }

        return min(costs[n-1], costs[n-2]);
    }
};