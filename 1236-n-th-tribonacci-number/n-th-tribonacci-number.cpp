class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) {
            return n;
        }
        if(n==2) {
            return 1;
        }
        int p=0, pp=1, ppp=1, curr;

        for(int i=3; i<=n; i++) {
            curr=p+pp+ppp;

            p=pp;
            pp=ppp;
            ppp=curr;
        }

        return curr;
    }
};