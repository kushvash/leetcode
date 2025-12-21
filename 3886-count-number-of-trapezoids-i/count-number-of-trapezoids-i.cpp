class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> yCount;
        long long MOD=1000000007, res=0, totalPairs=0;
        
        for(auto& p: points) {
            yCount[p[1]]++;
        }

        for(auto& [y, count]: yCount) {
            count%=MOD;
            int pair=(count*(count-1)/2)%MOD;

            res=(res+(pair*totalPairs))%MOD;

            totalPairs=(totalPairs+pair)%MOD;
        }

        return res;
    }
};