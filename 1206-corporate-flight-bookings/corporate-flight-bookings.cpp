class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        for(auto& booking: bookings) {
            int seats=booking[2];
            
            res[booking[0]-1]+=seats;

            if(booking[1]<n) {
                res[booking[1]]-=seats;
            }
        }

        // prefix sum array

        for(int i=0; i<n-1; i++) {
            res[i+1]+=res[i];
        }

        return res;
    }
};