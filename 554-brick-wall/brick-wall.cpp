class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> record;

        for(vector<int> row: wall){
            long long curr=0;
            for(int i=0; i<row.size()-1; i++){
                curr+=row[i];
                record[curr]++;
            }
        }
        int maxEdges=0;

        for(auto i: record){
            if(i.second>maxEdges){
                maxEdges=i.second;
            }
        }

        return wall.size()-maxEdges;
    }
};