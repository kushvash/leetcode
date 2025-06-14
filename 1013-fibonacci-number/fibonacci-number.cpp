class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }

        int prev=1, prev2=0, fibN;

        for(int i=2; i<=n; i++){
            fibN=prev+prev2;

            prev2=prev;
            prev=fibN;
        }

        return fibN;
    }
};