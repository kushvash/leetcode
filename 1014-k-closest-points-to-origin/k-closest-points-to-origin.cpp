class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> minHeap;
    
        for(vector<int> point: points) {
            int dist=point[0]*point[0] + point[1]*point[1];
            minHeap.push({dist, {point[0], point[1]}});
        }
        
        vector<vector<int>> res;
        for(int i=0; i<k; i++) {
            res.push_back({minHeap.top().second.first, minHeap.top().second.second});
            minHeap.pop();
        }

        return res;
    }
};