class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minX=m, minY=n;

        for(auto& op: ops) {
            minX=min(minX, op[0]);
            minY=min(minY, op[1]);
        }

        return minX*minY;
    }
};