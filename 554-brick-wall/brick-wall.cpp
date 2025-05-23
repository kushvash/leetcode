class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> record;
        int maxEdges=0;

        for(vector<int> row: wall){
            long long curr=0;
            for(int i=0; i<row.size()-1; i++){
                curr+=row[i];
                record[curr]++;

                if(record[curr]>maxEdges){
                    maxEdges=record[curr];
                }
            }
        }

        return wall.size()-maxEdges;
    }
};