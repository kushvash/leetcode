class Solution {
public:
    int numberOfWays(string corridor) {
        long long MOD=1000000007;

        int n=corridor.size(), totalSofas=0, currPlants=0;
        long long res=1;

        for(int i=0; i<n; i++) {
            if(totalSofas>0 && totalSofas%2==0) {
                if(corridor[i]=='P') {
                    currPlants++;
                }else {
                    res=((res*(currPlants+1))%MOD);
                    currPlants=0;
                    totalSofas++;
                }
            }else if(corridor[i]=='S') {
                totalSofas++;
            }
        }

        if(totalSofas==0 || totalSofas%2!=0) {
            return 0;
        }

        return res;
    }
};