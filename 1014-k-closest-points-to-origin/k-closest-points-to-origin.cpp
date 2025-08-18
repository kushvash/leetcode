class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<long long, vector<vector<int>>> record;
        vector<vector<int>> ans;

        for(auto point: points){
            long long x=point[0]*point[0];
            long long y=point[1]*point[1];
            long long tempDist=x+y;
            record[tempDist].push_back(point);
        }

        for(auto dist: record){
            for(auto point: dist.second){
                ans.push_back(point);
                if(ans.size()==k){
                    return ans;
                }
            }
        }

        return ans;
    }
};