class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2){
            return n;
        }
        int ll=1, l=2;

        for(int i=0; i<n-2; i++){
            int temp=l;
            l+=ll;
            ll=temp;
        }

        return l;
    }
};