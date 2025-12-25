class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        for(auto& booking: bookings) {
            int seats=booking[2];
            int first=booking[0];
            int last=booking[1];

            res[first-1]+=seats;
            if(last<n) {
                res[last]-=seats;
            }
        }

        for(int i=1; i<n; i++) {
            res[i]+=res[i-1];
        }

        return res;
    }
};