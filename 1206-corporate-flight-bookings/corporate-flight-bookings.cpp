class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diffArr(n, 0);

        for(vector<int>& booking: bookings) {
            int fi=booking[0], la=booking[1], seats=booking[2];

            diffArr[fi-1]+=seats;
            if(la<n) {
                diffArr[la]-=seats;
            }
        }

        for(int i=1; i<n; i++) {
            diffArr[i]+=diffArr[i-1];
        }

        return diffArr;
    }
};