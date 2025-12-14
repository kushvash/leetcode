class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size(), currS=0, currP=0, MOD=1000000007, totalS=0;
        long long res=1;

        for(int i=0; i<n; i++) {
            if(currS==2) {
                if(corridor[i]=='P') {
                    currP++;
                }else {
                    res*=(currP+1);
                    currS=1;
                    currP=0;
                    totalS++;
                }
            }else if(corridor[i]=='S'){
                currS++;
                totalS++;
            }

            res%=MOD;
        }

        if(currS==1 || totalS==0 || totalS%2==1) {
            return 0;
        }

        return res;
    }
};