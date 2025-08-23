class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0, n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> newInterval=intervals[0];
        vector<vector<int>> res;

        while(i<n){
            if(intervals[i][0]<=newInterval[1]){
                newInterval[1]=max(newInterval[1], intervals[i][1]);
            }else{
                res.push_back(newInterval);
                newInterval=intervals[i];
            }
            i++;
        }

        res.push_back(newInterval);
        
        return res;
    }
};