class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1000000007LL;

        // Your original single-pass logic, but using a separate counter for seats seen so far
        long long res = 1;
        int seatsSeen = 0, currP = 0;

        for (char c : corridor) {
            if (seatsSeen > 0 && (seatsSeen % 2) == 0) {   // between completed pairs
                if (c == 'P') {
                    currP++;
                } else { // 'S' -> start next pair
                    res = (res * (currP + 1)) % MOD;
                    currP = 0;
                    seatsSeen++;
                }
            } else if (c == 'S') {
                seatsSeen++;
            }
        }

        if (seatsSeen == 0 || (seatsSeen % 2) == 1) {
            return 0;
        }

        return (int)res;
    }
};