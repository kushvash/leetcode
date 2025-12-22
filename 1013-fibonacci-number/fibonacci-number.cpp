class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) {
            return n;
        }

        int prev=1, prevPrev=0, curr;

        for(int i=2; i<=n; i++) {
            curr=prev+prevPrev;

            prevPrev=prev;
            prev=curr;
        }

        return curr;
    }
};