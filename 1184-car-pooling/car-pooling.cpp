class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diffArray(1001, 0);

        for(vector<int>& trip: trips) {
            int pas=trip[0];
            int from=trip[1];
            int to=trip[2];

            diffArray[from]+=pas;

            if(diffArray[from]>capacity) {
                return false;
            }

            diffArray[to]-=pas;
        }

        for(int i=1; i<1001; i++) {
            diffArray[i]+=diffArray[i-1];

            if(diffArray[i]>capacity) {
                return false;
            }
        }

        return true;
    }
};