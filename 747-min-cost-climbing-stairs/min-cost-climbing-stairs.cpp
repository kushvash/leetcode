class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size(), last=cost[1], last2=cost[0];
      
        for(int i=2; i<n; i++){
            int temp=cost[i]+min(last, last2);
            last2=last;
            last=temp;
        }

        return min(last, last2);
    }
};