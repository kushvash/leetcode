class Solution {
public:
    int numberOfWays(string corridor) {
        long long MOD=1000000007, res=1, n=corridor.size(), sCount=0, pCount=0;

        for(int i=0; i<n; i++) {
            if(sCount>0 && sCount%2==0) {
                if(corridor[i]=='P') {
                    pCount++;
                }else {
                    res=(res*(pCount+1))%MOD;
                    sCount++;
                    pCount=0;
                }
            }else if(corridor[i]=='S'){
                sCount++;
            }
        }

        if(sCount%2!=0 || sCount==0) {
            return 0;
        }

        return res;
    }
};