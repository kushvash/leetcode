class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size(), currP=0, MOD=1000000007, totalS=0;
        long long res=1;

        for(int i=0; i<n; i++) {
            if(totalS>0 && totalS%2==0) {
                if(corridor[i]=='P') {
                    currP++;
                }else {
                    res*=(currP+1);
                    res%=MOD;
                    currP=0;
                    totalS++;
                }
            }else if(corridor[i]=='S'){
                totalS++;
            }
        }

        if(totalS==0 || totalS%2==1) {
            return 0;
        }

        return res;
    }
};