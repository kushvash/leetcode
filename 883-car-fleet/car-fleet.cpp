class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size(), res=1, prev=n-1;
        vector<pair<int, int>> fleet;

        for(int i=0; i<n; i++) {
            fleet.push_back({position[i], speed[i]});
        }

        sort(fleet.begin(), fleet.end());

        for(int i=n-2; i>=0; i--) {
            double timeTaken=(double)(target-fleet[i].first)/fleet[i].second;

            if(timeTaken>(double)(target-fleet[prev].first)/fleet[prev].second) {
                prev=i;
                res++;
            }
        }

        return res;
    }
};