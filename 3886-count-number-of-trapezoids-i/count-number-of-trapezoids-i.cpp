class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long MOD = 1000000007LL;
        unordered_map<int, long long> records;
        
        for(auto& point: points) {
            records[point[1]]++;
        }

        long long res=0, totalPairs=0;

        for(auto& record: records) {
            long long count = record.second%MOD;
            long long pair=(count*(count-1)/2)%MOD;

            res=(res+pair*totalPairs)%MOD;
            totalPairs=(totalPairs+pair)%MOD;
        } 

        return (int)res;
    }
};