class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res=0, n=intervals.size();

        auto cmp=[](vector<int>& a, vector<int>& b) {
            return a[0]<b[0];
        };

        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0; i<n; i++) {
            while(!minHeap.empty() && minHeap.top()<=intervals[i][0]) {
                minHeap.pop();
            }

            minHeap.push(intervals[i][1]);

            res=max(res, (int)minHeap.size());
        }

        return res;
    }
};