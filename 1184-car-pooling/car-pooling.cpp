class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> helper(1001, 0);

        int maxTo=0;

        for(auto& trip: trips) {
            int pas=trip[0], from=trip[1], to=trip[2];

            helper[from]+=pas;
            
            if(helper[from]>capacity) {
                return false;
            }

            if(to < 1000) {
                helper[to]-=pas;
            }

            maxTo=max(maxTo, to);
        }

        for(int i=0; i<maxTo; i++) {
            helper[i+1]+=helper[i];

            if(helper[i+1]>capacity) {
                return false;
            }
        }

        return true;
    }
};