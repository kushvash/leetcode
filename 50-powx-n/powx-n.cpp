class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        double res = helper(x, abs(static_cast<long>(n)));
        return (n >= 0) ? res : 1 / res;
    }

    double helper(double x, int n){
        if(n==0){
            return 1;
        }

        double temp=helper(x, n/2);
        
        if(n%2==0){
            return temp*temp;
        }

        return temp*temp*x;
    }
};