class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1]; // sort by end
             });

        int n = (int)events.size();
        vector<int> ends(n), bestUpTo(n);

        for (int i = 0; i < n; ++i) {
            ends[i] = events[i][1];
            bestUpTo[i] = events[i][2];
            if (i > 0) bestUpTo[i] = max(bestUpTo[i], bestUpTo[i - 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int s = events[i][0], v = events[i][2];
            ans = max(ans, v); // take only this event

            // find last event with end < start (non-overlapping; endpoints are inclusive)
            int idx = (int)(lower_bound(ends.begin(), ends.end(), s) - ends.begin()) - 1;
            if (idx >= 0) ans = max(ans, v + bestUpTo[idx]);
        }

        return ans;
    }
};