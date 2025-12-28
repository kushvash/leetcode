class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long MOD=1000000007, totalPairs=0, res=0;

        unordered_map<int, long long> yCount;

        for(vector<int>& point: points) {
            yCount[point[1]]++;
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