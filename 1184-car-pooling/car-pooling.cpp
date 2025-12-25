class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> numPass(1001, 0);

        for(auto& trip: trips) {
            int pas=trip[0];
            int from=trip[1];
            int to=trip[2];

            numPass[from]+=pas;
            numPass[to]-=pas;
        }

        if(numPass[0]>capacity) {
            return false;
        }

        for(int i=1; i<1001; i++) {
            numPass[i]+=numPass[i-1];
            if(numPass[i]>capacity) {
                return false;
            }
        }

        return true;
    }
};